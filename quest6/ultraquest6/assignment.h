#pragma once
#include <string>
using namespace std;

class Assignment {
private:
    string name;
    float percentage;

public:
    Assignment(string n);

    string getName() const;
    void setGrade(float grade);
    float getPercentage() const;
};
