#include <iostream>
#include <cmath>
using namespace std;

/* -------------------------------------------------------------------------------

Function Name: hypotenuse

Parameters: double a, double b

Return type: double

Description: hypotenuse takes as input two side lengths of a triangle and uses the Pythagorean theorem to compute the hypotenuse of the triangle, which is then returned/output.

-----------------------------------------------------------------------------------*/

double hypotenuse(double a, double b) {
    return sqrt(a * a + b * b);
}

int main() {
    double side1, side2;
    cin >> side1 >> side2;

    cout << "Length: " << hypotenuse(side1, side2) << endl;

    return 0;
}