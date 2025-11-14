#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Mine {
    int x, y;
    bool exploded;
};

struct Node {
    int x, y;
    Node* prev;
};

// logic for checking if a position has been visited

/*
bool isVisited(Node* head, int x, int y) {
    for (Node* t = head; t; t = t->prev)
        if (t->x == x && t->y == y) return true;
    return false;
}
    */

// printing the grid (also shows exploded mines as 'B')
void printGrid(Node* head, int vertical, int horizontal, Mine mines[], int n, int height, int width) {
    cout << "\n";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == vertical && j == horizontal) cout << " P ";
            else {
                // show exploded bombs
                bool printed = false;
                for (int m = 0; m < n; ++m) {
                    if (mines[m].exploded && mines[m].x == j && mines[m].y == i) {
                        cout << " B ";
                        printed = true;
                        break;
                    }
                }
                if (printed) continue;

                bool paintedHere = false;
                for (Node* t = head; t; t = t->prev) {
                    if (t->x == j && t->y == i) {
                        paintedHere = true;
                        break;
                    }
                }
                if (paintedHere) cout << " # ";
                else cout << " . ";
            }
        }
        cout << "\n";
    }
}

int main() {
    srand(time(0));
    const int WIDTH = 20, HEIGHT = 20;
    int n;

    cout << "Give number of landmines: ";
    cin >> n;

    if (n > WIDTH * HEIGHT) n = WIDTH * HEIGHT;
    if (n < 0) n = 0;

    //mine array
    Mine mines[400];

    // random mine locations
    for (int i = 0; i < n; ++i) {
        bool unique;
        int mx, my;
        do {
            unique = true;
            mx = rand() % WIDTH;
            my = rand() % HEIGHT;
            for (int j = 0; j < i; ++j)
                if (mines[j].x == mx && mines[j].y == my)
                    unique = false;
        } while (!unique);
        mines[i] = {mx, my, false};
    }

    // set up first player location and state
    Node* head = new Node{10, 10, nullptr};
    int x = 10, y = 10;
    int painted = 1;
    int limbs = 5;

    cout << "\nstarted at 10,10 with 5 limbs. good luck bucko\n";

    // edge case for mine at starting location
    for (int i = 0; i < n; ++i) {
        // check if a mine is right where the player starts
        if (!mines[i].exploded && mines[i].x == y && mines[i].y == x) {
            cout << "\nboomboom someone dont got a limb no more\n";
            limbs--;
            mines[i].exploded = true; //mark as explodified
            break;
        }
    }

    // game loop
    while (true) {
    printGrid(head, x, y, mines, n, HEIGHT, WIDTH);
        cout << "painted: " << painted << "   limbs: " << limbs << "\nwasd to move: ";

        char move;
        cin >> move;
        int vertical = x, horizontal = y;

        if (move == 'W' || move == 'w') vertical--;
        else if (move == 'S' || move == 's') vertical++;
        else if (move == 'A' || move == 'a') horizontal--;
        else if (move == 'D' || move == 'd') horizontal++;
        else continue;

        if (!(vertical >= 0 && vertical < 20 && horizontal >= 0 && horizontal < 20)) {
            cout << "can't leave the garage bro.\n";
            continue;
        }

        bool visited = false;
        for (Node* t = head; t; t = t->prev)
            if (t->x == horizontal && t->y == vertical) {
                visited = true;
                break;
            }

        bool backtrack = (head->prev && head->prev->x == horizontal && head->prev->y == vertical);

        if (visited && !backtrack) {
            cout << "\nouta paint idiot\n";
            cout << "total painted: " << painted << " sq ft.\n";
            break;
        }

        if (backtrack) {
            head = head->prev;
            x = vertical; y = horizontal;
            continue;
        }

    // create new node
    Node* node = new Node{horizontal, vertical, head};
        head = node;
        x = vertical; y = horizontal;
        painted++;

        // landmine check (only trigger un-exploded mines)
        for (int i = 0; i < n; ++i) {
            // compare to the node's coordinates (node->x is horizontal, node->y is vertical)
            if (!mines[i].exploded && mines[i].x == node->x && mines[i].y == node->y) {
                cout << "\nboomboom someone dont got a limb no more\n";
                limbs--;
                mines[i].exploded = true; // mark exploded so we can show it on the grid
                break;
            }
        }

        if (limbs == 0) {
            cout << "\n;( no more limbs for you\n";
            cout << "total amount before death: " << painted << " sq ft.\n";
            break;
        }

        if (painted == WIDTH * HEIGHT) {
            cout << "\nHOW THE HECK DID U DO THAT\n";
            break;
        }
    }

    // cleanup
    while (head) {
        Node* t = head;
        head = head->prev;
        delete t;
    }
}
