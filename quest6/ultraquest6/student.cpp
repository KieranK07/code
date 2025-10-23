#include "student.h"
#include <iostream>
using namespace std;

Student::Student(string fName, string lName)
    : firstName(fName), lastName(lName) {}

void Student::addAssignment(const Assignment& assignment) {
    assignments.push_back(assignment);
}

const vector<Assignment>& Student::getAssignments() const {
    return assignments;
}

void Student::enterGrade(const string& assignmentName, double grade) {
    for (auto& assignment : assignments) {
        if (assignment.getName() == assignmentName) {
            assignment.setGrade(grade);
            return;
        }
    }
    cout << "Assignment not found.\n";
}

string Student::getName() const {
    return firstName + " " + lastName;
}
