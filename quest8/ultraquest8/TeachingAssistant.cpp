#include "TeachingAssistant.h"
#include <iostream>
using namespace std;

void TeachingAssistant::printPersonInfo() {
    cout << "[TA] Name: " << name << ", ID: " << id << endl;
}

void TeachingAssistant::printTAInfo() {
    printPersonInfo();
    printStudentInfo();
    printInstructorInfo();
    cout << "Hours per week: " << hoursPerWeek << endl;
}
