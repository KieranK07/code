#include <iostream>
using namespace std;

int fibonacciLoop(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int a = 0;
    int b = 1;
    int fib = 0;


    for (int i = 2; i <= n; ++i) {
        fib = a + b;
        a = b;
        b = fib;
    }

    return fib;
};

int fibonacciRecursive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
};

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    cout << "Fibonacci (Loop): " << fibonacciLoop(n) << endl;
    cout << "Fibonacci (Recursive): " << fibonacciRecursive(n) << endl;
}