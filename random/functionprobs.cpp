#include <iostream>
using namespace std;

//nth fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "gimmeie postive int ";
    cin >> n;

    int result = fibonacci(n);
    cout << "Fibonacci(" << n << ") = " << result << endl;

    return 0;
}