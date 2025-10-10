//ultraquest 2
#include <iostream>
using namespace std;

int main() {

    //input status
    cout << "Input filing status:\n1. Single\n2. Married Filing Jointly\n3. Head of Household\n";
    int status;
    cin >> status;

    //income
    cout << "Input your income as a whole number: ";
    int income;
    double tax;
    //double totaltax;     removed because not needed
    cin >> income;

    //tax bracket switch
    //percentage only applies to the amount of income that falls within the range
    switch (status) {

        //tax brackets
        case 1: // Single
            if (income <= 10000) {
                tax = income * 0.10;
            //for each amount you add the previous max tax
            } else if (income >= 10001 && income <= 40000) {
                tax = 10000 * 0.10 + (income - 10000) * 0.12;
            } else if (income >= 40001 && income <= 85000) {
                tax = 10000 * 0.10 + 30000 * 0.12 + (income - 40000) * 0.22;
            } else if (income >= 85001) {
                tax = 10000 * 0.10 + 30000 * 0.12 + 45000 * 0.22 + (income - 85000) * 0.24;
            }
            // output total tax
            cout << "Total tax owed: $" << tax << endl;
            break;

        case 2: // Married Filing Jointly
            if (income <= 20000) {
                tax = income * 0.10;
            } else if (income >= 20001 && income <= 80000) {
                tax = 20000 * 0.10 + (income - 20000) * 0.12;
            } else if (income >= 80001 && income <= 171000) {
                tax = 20000 * 0.10 + 60000 * 0.12 + (income - 80000) * 0.22;
            } else if (income >= 171001) {
                tax = 20000 * 0.10 + 60000 * 0.12 + 91000 * 0.22 + (income - 171000) * 0.24;
            }
            cout << "Total tax owed: $" << tax << endl;
            break;

        case 3: // Head of Household
            if (income <= 14000) {
                tax = income * 0.10;
            } else if (income >= 14001 && income <= 55000) {
                tax = 14000 * 0.10 + (income - 14000) * 0.12;
            } else if (income >= 55001 && income <= 130000) {
                tax = 14000 * 0.10 + 41000 * 0.12 + (income - 55000) * 0.22;
            } else if (income >= 130001) {
                tax = 14000 * 0.10 + 41000 * 0.12 + 75000 * 0.22 + (income - 130000) * 0.24;
            }
            cout << "Total tax owed: $" << tax << endl;
            break;

        default:
            cout << "Invalid filing status.\n";
            break;
    }
    return 0;
}