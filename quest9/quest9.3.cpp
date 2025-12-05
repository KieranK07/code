#include <iostream>
using namespace std;

int collatz(int n) {
    cout << n << " ";

    // base case first
    if (n == 1) {
        cout << endl;
        return 1;
    }

    if (n % 2 == 0) {
        return collatz(n / 2);
    } else {
        return collatz(3 * n + 1);
    }
}

int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;
    collatz(number);
}