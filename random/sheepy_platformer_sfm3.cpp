// sheepy_platformer_sfm3.cpp
// Minimal platformer example for SFML 3.0.1
// Build: g++ sheepy_platformer_sfm3.cpp -o sheepy_platformer_sfm3 -IC:/SFML/include -LC:/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>
#include <vector>
#include <optional>

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr float GRAVITY = 0.5f;
constexpr float JUMP_VELOCITY = -12.0f;
constexpr float MOVE_SPEED = 5.0f;

struct Platform {
    sf::RectangleShape shape;
    Platform(float x, float y, float w, float h) {
        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize({w, h});
        shape.setFillColor(sf::Color(100, 60, 20));
    }
};

struct Player {
    sf::RectangleShape shape;
    sf::Vector2f velocity;
    bool onGround = false;
    Player(float x, float y) {
        shape.setSize({32, 48});
        shape.setFillColor(sf::Color(200, 200, 255));
        shape.setPosition(sf::Vector2f(x, y));
    }
    void move(float dx) {
        shape.move(sf::Vector2f(dx, 0));
    }
    void jump() {
        if (onGround) velocity.y = JUMP_VELOCITY;
    }
    void update() {
        velocity.y += GRAVITY;
        shape.move(sf::Vector2f(0, velocity.y));
    }
};

struct Collectible {
    sf::CircleShape shape;
    bool collected = false;
    Collectible(float x, float y) {
        shape.setRadius(12);
        shape.setFillColor(sf::Color::Yellow);
        shape.setPosition(sf::Vector2f(x, y));
    }
};

struct Enemy {
    sf::RectangleShape shape;
    float leftBound, rightBound, speed;
    bool alive = true;
    Enemy(float x, float y, float w, float h, float l, float r, float s) : leftBound(l), rightBound(r), speed(s) {
        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize({w, h});
        shape.setFillColor(sf::Color::Red);
    }
    void update() {
        if (!alive) return;
        auto pos = shape.getPosition();
        pos.x += speed;
        if (pos.x < leftBound || pos.x > rightBound) speed = -speed;
        shape.setPosition(pos);
    }
};

bool checkCollision(const sf::RectangleShape& a, const sf::RectangleShape& b) {
    auto rectA = a.getGlobalBounds();
    auto rectB = b.getGlobalBounds();
    return rectA.position.x < rectB.position.x + rectB.size.x &&
           rectA.position.x + rectA.size.x > rectB.position.x &&
           rectA.position.y < rectB.position.y + rectB.size.y &&
           rectA.position.y + rectA.size.y > rectB.position.y;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT)), "Sheepy Platformer SFML 3");
    window.setFramerateLimit(60);

    Player player(100, 400);
    std::vector<Platform> platforms = {
        Platform(0, 550, 800, 50),
        Platform(200, 450, 120, 20),
        Platform(400, 350, 120, 20),
        Platform(600, 250, 120, 20)
    };
    Collectible collectible(420, 310);
    Enemy enemy(300, 520, 32, 32, 300, 500, 2.0f);

    bool gameOver = false;
    bool win = false;

    while (window.isOpen()) {
        for (auto event = window.pollEvent(); event.has_value(); event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        if (!gameOver && !win) {
            float dx = 0;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) dx -= MOVE_SPEED;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) dx += MOVE_SPEED;
            player.move(dx);
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) && player.onGround) player.jump();

            player.onGround = false;
            player.update();

            for (auto& plat : platforms) {
                if (checkCollision(player.shape, plat.shape)) {
                    auto p = player.shape.getPosition();
                    auto v = player.velocity;
                    if (v.y > 0) {
                        player.shape.setPosition(sf::Vector2f(p.x, plat.shape.getPosition().y - player.shape.getSize().y));
                        player.velocity.y = 0;
                        player.onGround = true;
                    } else if (v.y < 0) {
                        player.shape.setPosition(sf::Vector2f(p.x, plat.shape.getPosition().y + plat.shape.getSize().y));
                        player.velocity.y = 0.5f;
                    }
                }
            }

            enemy.update();
            if (enemy.alive && checkCollision(player.shape, enemy.shape)) {
                gameOver = true;
            }
            if (!collectible.collected && checkCollision(player.shape, collectible.shape)) {
                collectible.collected = true;
                win = true;
            }
        }

        window.clear(sf::Color(30, 30, 60));
        for (auto& plat : platforms) window.draw(plat.shape);
        if (!collectible.collected) window.draw(collectible.shape);
        if (enemy.alive) window.draw(enemy.shape);
        window.draw(player.shape);
        window.display();
    }
    return 0;
}
