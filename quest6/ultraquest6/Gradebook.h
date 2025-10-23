#pragma once
#include "student.h"
#include "assignment.h"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

class Gradebook {
private:
    vector<Student> students; // vector of student objects

public:
    void addStudent(const Student& student);
    void addAssignment(const Assignment& assignment);
    void enterGrade(const string& studentName, const string& assignmentName, double grade);
    void printGradebook();
};