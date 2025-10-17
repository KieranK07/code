//class to contain vector of student objects
#pragma once
#include "student.h"
#include "assignment.h"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

class Gradebook {
private:
    vector<Student> students; //vector of student objects
public:
    // add student
    void addStudent(const Student& student) {
        students.push_back(student);
    }
    
    // add assignment to all students
    void addAssignment(const Assignment& assignment) {
        for (auto& student : students) {
            student.addAssignment(assignment);
        }
    }

    // enter grade for a student's assignment
    void enterGrade(const string& studentName, const string& assignmentName, double grade) {
        for (auto& student : students) {
            if (student.getName() == studentName) {
                student.enterGrade(assignmentName, grade);
                return;
            }
        }
        cout << "Student not found.\n";
    }

    // print gradebook
    void printGradebook() {
    if (students.empty()) {
        cout << "No students in gradebook.\n";
        return;
    }

    const vector<Assignment>& firstAssignments = students[0].getAssignments();
    const int width = 15;

    cout << left << setw(width) << "Student";
    for (const auto& a : firstAssignments)
        cout << left << setw(width) << a.getName();
    cout << "\n" << string(width * (firstAssignments.size() + 1), '-') << "\n";

    for (const auto& s : students) {
        cout << left << setw(width) << s.getName();
        const vector<Assignment>& aList = s.getAssignments();
        for (const auto& a : aList) {
            if (a.getPercentage() == 0)
                cout << left << setw(width) << "-";
            else
                cout << left << setw(width) << fixed << setprecision(1) << a.getPercentage();
        }
        cout << "\n";
    }
}

};