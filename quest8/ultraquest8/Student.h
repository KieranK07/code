#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : virtual public Person {
public:
    float gpa;

    void printStudentInfo();
};

#endif
