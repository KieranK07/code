#include <iostream>
#include <vector>
using namespace std;

int main() {
    //input int vector of any size, including negatives
    vector<int> vec;
    int input;

    while (true) {
        cout << "enter an int or q to quit: ";
        cin >> input;

        if (cin.fail()) {
            cin.clear(); // clear the error flag
            string exitLoop;
            cin >> exitLoop;
            if (exitLoop == "q") break; // quit if user enters 'q'
            cout << "invalid, please enter an integer.\n";
            continue;
        }

        vec.push_back(input);
    }

    //iterate through subarrays of every length, starting at one and moving to the max length
    for (int length = 1; length <= vec.size(); length++) {
        cout << "Subarrays of length " << length << ":\n";
        for (int start = 0; start <= vec.size() - length; start++) {
            int sum = 0;
            cout << "  [";
            for (int i = start; i < start + length; i++) {
                cout << vec[i];
                sum += vec[i];
                if (i < start + length - 1)
                    cout << ", ";
            }
            cout << "] Sum: " << sum << "\n";
        }
    }
}