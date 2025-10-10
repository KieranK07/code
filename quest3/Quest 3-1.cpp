#include <iostream>
#include <limits>
using namespace std;

int main() {
    cout << "Menu:\n";
    cout << "1. Pizza\n";
    cout << "2. Hotdog\n";
    cout << "3. Taco\n";
    cout << "4. Shrimp and Grits\n";

    int choice = 0;
    cout << "Enter your choice (1-4): ";
    cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number between 1 and 4: ";
        cin >> choice;
    }
    cout << "You selected option " << choice << endl;

    return 0;
}