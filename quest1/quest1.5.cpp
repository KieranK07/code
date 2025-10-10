#include <iostream>
using namespace std;

int main() {

    int a,b,c,d;
    cout << "Enter a:\n";
    cin >> a;
    cout << "Enter b:\n";
    cin >> b;
    cout << "Enter c:\n";
    cin >> c;
    cout << "Enter d:\n";
    cin >> d;

    int cx;
    cout << "Enter a value for x:\n";
    cin >> cx;

    int ans;
    ans = (a * (cx * cx * cx)) + (b * (cx * cx)) + (c * cx) + d;

    cout << "The output of " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << " is: " << ans;

    return 0;
}