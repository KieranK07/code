#include "TeachingAssistant.h"

int main() {
    TeachingAssistant ta;

    ta.name = "walter";
    ta.id = 42;
    ta.gpa = 6.7f;
    ta.department = "comp sci";
    ta.hoursPerWeek = 21;

    ta.printPersonInfo();
    ta.printStudentInfo();
    ta.printInstructorInfo();
    ta.printTAInfo();

    return 0;
}
