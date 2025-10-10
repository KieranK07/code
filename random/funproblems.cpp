#include <iostream>
using namespace std;
//
int n;

int main() {
    cout << "Input number";
    //2n-1 tall, 2n-1 wide
    cin >> n;
    //hollow diamond generator
    // Upper half of the diamond
    for (int i = 0; i < n; i++) {
        // i is counting rows
        for (int j = 0; j <= 2 * n - 2; j++) {
            // j is counting columns
            if (j == n + i - 1 || j == n - i - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    // Lower half of the diamond
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= 2 * n - 2; j++) {
            if (j == n + i - 1 || j == n - i - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}