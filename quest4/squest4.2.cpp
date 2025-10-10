#include <iostream>
using namespace std;

int guess;
int count;

int main() {

    srand(time(0));
    int answer = rand() % 20 + 1;
    cout << "Guess a number between 1 and 20: ";
    while (true) {
        cin >> guess;
        count++;
        if (guess < answer) {
            cout << "higher";
        } else if (guess > answer) {
            cout << "lower";
        } else {
            cout << "yurp the answer is " << answer << endl;
            cout << "took u " << count << " tries" << endl;
            break;
        }
    }
}