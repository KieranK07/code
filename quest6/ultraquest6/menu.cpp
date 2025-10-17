// main menu
#include <iostream>
#include "Gradebook.h"
#include "student.h"
#include "assignment.h"
using namespace std;

void clear() {
    cout << "\033[2J\033[1;1H"; // clear screen
}

int main() {
    Gradebook gb;
    while (true) {
        clear();
        cout << "Gradebook Menu:\n";
        cout << "1. Add Student to Gradebook\n";
        cout << "2. Add Assignment to Gradebook\n";
        cout << "3. Enter a grade for an assignment\n";
        cout << "4. Print full gradebook\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            while (true) {
                clear();
                string fName, lName, yesNo;
                cout << "Enter first name: ";
                cin >> fName;
                cout << "Enter last name: ";
                cin >> lName;
                // add student to gradebook
                gb.addStudent(Student(fName, lName));
                cout << "Student added.\n";
                cout << "Add another student? (y/n): ";
                cin >> yesNo;
                if (yesNo != "y") {
                    break;
                }
            }
        } else if (choice == 2) {
            while (true) {
                clear();
                string title, yesNo;
                cout << "Enter assignment title: ";
                cin >> title;
                // add assignment to gradebook
                gb.addAssignment(Assignment(title));
                cout << "Assignment added.\n";
                cout << "Add another assignment? (y/n): ";
                cin >> yesNo;
                if (yesNo != "y") {
                    break;
                }
            }
        } else if (choice == 3) {
            while (true) {
                clear();
                string firstName, lastName, title, yesNo;
                double grade;
                cout << "Enter first name: ";
                cin >> firstName;
                cout << "Enter last name: ";
                cin >> lastName;
                cout << "Enter assignment title: ";
                cin >> title;
                cout << "Enter grade: ";
                cin >> grade;
                // enter assignment
                gb.enterGrade(firstName + " " + lastName, title, grade);
                cout << "Enter another grade? (y/n): ";
                cin >> yesNo;
                if (yesNo != "y") {
                    break;
                }
            }
        } else if (choice == 4) {
            clear();
            gb.printGradebook();
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        } else if (choice == 5) {
            break;
        } else {
            clear();
            cout << "invalid choice. please try again.\n";
        }
    }
}

