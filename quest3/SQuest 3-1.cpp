#include <iostream>
using namespace std;

int main() {
    cout << "Guess the lucky number between 1 and 100!\n";
    int numguesses = 0;
    int guess = 0;
    // random number between 1 and 100
    int luckynum = 36;
    
    //loop 10 times or until correct
    while (numguesses < 10 && guess != luckynum) {
        cout << "Enter guess: ";
        cin >> guess;
        numguesses = numguesses + 1;
        if (guess < 1 || guess > 100) {
            cout << "invalid\n";
            numguesses = numguesses - 1;
            continue;
        }

        if (guess == luckynum) {
            cout << "yurp it was " << luckynum << " and u got it in " << numguesses << " guesses\n";
            return 0;
        }
    }
    cout << "womp womp u lost the number was  " << luckynum << endl;
    return 0;
}
