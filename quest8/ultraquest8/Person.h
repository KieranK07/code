#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    std::string name;
    int id;

    virtual void printPersonInfo();
};

#endif
