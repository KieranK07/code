//class to contain vector of assignment objects
// Student's first name
// Student's last name
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Gradebook.h"
#include "assignment.h"
using namespace std;



class Student {
private:
    string firstName;
    string lastName;
    vector<Assignment> assignments; //vector of assignment objects
public:
    Student(string fName, string lName) : firstName(fName), lastName(lName) {}

    void addAssignment(const Assignment& assignment) {
        assignments.push_back(assignment);
    }

    const vector<Assignment>& getAssignments() const {
        return assignments;
    }

    void enterGrade(const string& assignmentName, double grade) {
        for (auto& assignment : assignments) {
            if (assignment.getName() == assignmentName) {
                assignment.setGrade(grade);
                return;
            }
        }
        cout << "Assignment not found.\n";
    }

    string getName() const {
        return firstName + " " + lastName;
    }
};