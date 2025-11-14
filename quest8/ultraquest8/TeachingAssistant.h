#ifndef TEACHINGASSISTANT_H
#define TEACHINGASSISTANT_H

#include "Student.h"
#include "Instructor.h"

class TeachingAssistant : public Student, public Instructor {
public:
    int hoursPerWeek;

    void printPersonInfo() override; 
    void printTAInfo();
};

#endif
