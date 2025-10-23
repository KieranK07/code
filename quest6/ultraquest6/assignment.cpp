#include "assignment.h"

Assignment::Assignment(string n)
    : name(n), percentage(0.0f) {}

string Assignment::getName() const {
    return name;
}

void Assignment::setGrade(float grade) {
    percentage = grade;
}

float Assignment::getPercentage() const {
    return percentage;
}
