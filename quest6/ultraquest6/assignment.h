//class to contain assignment name and student percentage score
#pragma once
#include <string>
#include "Gradebook.h"
#include "student.h"
using namespace std;

class Assignment {
private:
    string name;
    float percentage;
public:
    Assignment(string n) : name(n), percentage(0.0f) {}

    string getName() const {
        return name;
    }

    void setGrade(float grade) {
        percentage = grade;
    }

    float getPercentage() const {
        return percentage;
    }
};
