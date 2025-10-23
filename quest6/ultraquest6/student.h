#pragma once
#include <string>
#include <vector>
#include "assignment.h"
using namespace std;

class Student {
private:
    string firstName;
    string lastName;
    vector<Assignment> assignments; // vector of assignment objects

public:
    Student(string fName, string lName);

    void addAssignment(const Assignment& assignment);
    const vector<Assignment>& getAssignments() const;
    void enterGrade(const string& assignmentName, double grade);
    string getName() const;
};
