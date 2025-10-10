// input int and convert to prime factorization string, bases in increasing order
// exponants = '^'
// times = ' '
// example =         100 = 2^5 3^2

#include <iostream>
#include <string>
using namespace std;

int main() {
    // get positive integer inputs
    int input = 0;
    cout << "Enter a positive integer: ";
    cin >> input;
    // make sure input is positive
    while (input < 1) {
        cout << "Invalid input. Please enter a positive integer: ";
        cin >> input;
    }
    // for each integer i from 2 to input
    int number = input;
    string finalout = "";

    // loop through all numbers from 2 up to n to find prime numbers
    for (int i = 2; number > 1; i++) {
        int count = 0; // this counts how many times i divides n

        // while i is divisible by num divide num by i and count up
        while (number % i == 0) {
            number = number / i;
            count = count + 1;
        }

        // if i goes into n once add it
        if (count > 0) {
            finalout = finalout + to_string(i); // add base

            // if its more than one add it
            if (count > 1) {
                finalout = finalout + "^" + to_string(count); // add exponent
            }

            // if theres extra add a space
            if (number > 1) {
                finalout = finalout + " ";
            }
        }
    }
    // print everything back out again with the solution
    cout << input << " = " << finalout << endl;
    return 0;
}

