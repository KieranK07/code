#include <iostream>
#include <chrono>
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
}

int fibonacciRecursive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main() {
    int n;
    cout << "enter a positive integer: ";
    cin >> n;

    // loop timing
    auto startLoop = chrono::high_resolution_clock::now();
    int loopResult = fibonacciLoop(n);
    auto endLoop = chrono::high_resolution_clock::now();

    // recursive timing
    auto startRec = chrono::high_resolution_clock::now();
    int recResult = fibonacciRecursive(n);
    auto endRec = chrono::high_resolution_clock::now();

    cout << "fib loop: " << loopResult << endl;
    cout << "time for loop: "
         << chrono::duration_cast<chrono::microseconds>(endLoop - startLoop).count()
         << " microseconds\n";

    cout << "fib recursive: " << recResult << endl;
    cout << "time for recursive: "
         << chrono::duration_cast<chrono::microseconds>(endRec - startRec).count()
         << " microseconds\n";
}
