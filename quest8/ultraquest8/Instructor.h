#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "Person.h"
#include <string>

class Instructor : virtual public Person {
public:
    std::string department;

    void printInstructorInfo();
};

#endif
