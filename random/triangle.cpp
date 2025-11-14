#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    double findArea() { 
        return 0;
    }

    double findPerimeter() { 
        return 0;
    }
};

class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}

    double findArea() {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double findPerimeter() {
        return a + b + c;
    }
};

int main() {
    double side1, side2, side3;
    cout << "enter the three side lengths: ";
    cin >> side1;
    cin >> side2;
    cin >> side3;

    Triangle triangle(side1, side2, side3);

    cout << "area: " << triangle.findArea() << endl;
    cout << "perimeter: " << triangle.findPerimeter() << endl;

    return 0;
}
