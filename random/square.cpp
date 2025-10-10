#include <iostream>
using namespace std;

int main() {
    int input = 1;
    while (input != 0) {
        cout << "Enter a number between 1 and 100 (0 to exit): ";
        cin >> input;
        if (input >= 1 && input <= 100) {
            cout << "Here is your square: " << (input * input) << endl;
        } else if (input != 0) {
            cout << "You had one job. Really, was it that hard?" << endl;
            break;
        }

    }
    cout << "Goodbye." << endl;
}