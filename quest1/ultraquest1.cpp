// #include <iostream>
// using namespace std;

// int main() {
//     //gimmie dat money
//     double money;
//     cout << "Input amount of money:\n";
//     cin >> money;
//     cout << "Amount of money entered:\n" << money;


//     //divide out the hundred dollar bills
//     double hundreds = money / 100;
//     // separate the number of hundred bills and the rest of the decimals
//     double singlehundreds = static_cast<int>(hundreds);
//     double leftoverhundreds = hundreds - singlehundreds;
//     cout << "\nThis many hundred dollar bills: " << singlehundreds << endl;
//     //print the rest of the decimals
//     cout << "Remaining money after hundreds: " << leftoverhundreds * 100 << endl;

//     leftoverhundreds = leftoverhundreds * 100;

//     //divide out the twenties
//     double twenties = leftoverhundreds / 20;
//     // separate the number of twenty bills and the rest of the decimals
//     double singletwenties = static_cast<int>(twenties);
//     double leftovertwenties = twenties - singletwenties;
//     cout << "\nThis many twenty dollar bills: " << singletwenties << endl;
//     //print the rest of the decimals
//     cout << "Remaining money after twenties: " << leftovertwenties * 20<< endl;

//     leftovertwenties = leftovertwenties * 20;

//     //divide out the tens
//     double tens = leftovertwenties / 10;
//     // separate the number of ten bills and the rest of the decimals
//     double singletens = static_cast<int>(tens);
//     double leftovertens = tens - singletens;
//     cout << "\nThis many ten dollar bills: " << singletens << endl;
//     //print the rest of the decimals
//     cout << "Remaining money after tens: " << leftovertens * 10 << endl;

//     leftovertens = leftovertens * 10;

//     //divide out the fives
//     double fives = leftovertens / 5;
//     // separate the number of five bills and the rest of the decimals
//     double singlefives = static_cast<int>(fives);
//     double leftoverfives = fives - singlefives;
//     cout << "\nThis many five dollar bills: " << singlefives << endl;
//     //print the rest of the decimals
//     cout << "Remaining money after fives: " << leftoverfives * 5 << endl;

//     leftoverfives = leftoverfives * 5;

//     //divide out the ones
//     double ones = leftoverfives / 1;
//     // separate the number of ome bills and the rest of the decimals
//     double singleones = static_cast<int>(ones);
//     double leftoverones = ones - singleones;
//     cout << "\nThis many one dollar bills: " << singleones << endl;
//     //print the rest of the decimals
//     cout << "Remaining money after ones: " << leftoverones * 1 << endl;

//     leftoverfives = leftoverfives * 1;

//     //this section will figure out how many quarters, dimes, nickles, and pennies are left

//     //quarters
//     double quarters = leftoverones / 0.25;
//     // separate the number of quarter bills and the rest of the decimals
//     double singlequarters = static_cast<int>(quarters);
//     double leftoverquarters = quarters - singlequarters;
//     cout << "\nThis many quarters: " << singlequarters << endl;
//     //print the rest of the decimals
//     cout << "Remaining money after quarters: " << leftoverquarters * 0.25 << endl;

//     leftoverquarters = leftoverquarters * 0.25;

//     //dimes
//     double dimes = leftoverquarters / 0.1;
//     // separate the number of dime bills and the rest of the decimals
//     double singledimes = static_cast<int>(dimes);
//     double leftoverdimes = dimes - singledimes;
//     cout << "\nThis many dimes: " << singledimes << endl;
//     //print the rest of the decimals
//     cout << "Remaining money after dimes: " << leftoverdimes * 0.1 << endl;

//     leftoverdimes = leftoverdimes * 0.1;

//     //nickels
//     double nickels = leftoverdimes / 0.05;
//     // separate the number of nickel bills and the rest of the decimals
//     double singlenickels = static_cast<int>(nickels);
//     double leftovernickels = nickels - singlenickels;
//     cout << "\nThis many nickels: " << singlenickels << endl;
//     //print the rest of the decimals
//     cout << "Remaining money after nickels: " << leftovernickels * 0.05 << endl;

//     leftovernickels = leftovernickels * 0.05;

//     //figure out the last couple pennies
//     double pennies = leftovernickels * 100;
//     cout << "\nThis many pennies: " << pennies << endl;

//     return 0;
// }




//starting over with cents based bc itll be simpler
//also double sucks


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double money;
    //input the moola
    cout << "Input amount of money:\n";
    cin >> money;

    int cents = static_cast<int>(money * 100.0);

    cout << "Amount of money entered in cents:\n" << cents << " cents" << endl;

    //hundreds
    //use remainder operator to pull out the amount i want
    int hundreds = cents / 10000; 
    cout << hundreds;
    cents = cents % 10000;
    //cout << "Leftover cents: " << cents << "\n\n";

    //twenties
    int twenties = cents / 2000;
    cents = cents % 2000;
    //cout << "Leftover cents: " << cents << "\n\n";

    //tens
    int tens = cents / 1000;
    cents = cents % 1000;
    //cout << "Leftover cents: " << cents << "\n\n";

    //fives
    int fives = cents / 500;
    cents = cents % 500;
    //cout << "Leftover cents: " << cents << "\n\n";

    //ones
    int ones = cents / 100;
    cents = cents % 100;
    //cout << "Leftover cents: " << cents << "\n\n";

    //quarters
    int quarters = cents / 25;
    cents = cents % 25;
    //cout << "Leftover cents: " << cents << "\n\n";
    
    //dimes
    int dimes = cents / 10;
    cents = cents % 10;
    //cout << "Leftover cents: " << cents << "\n\n";

    //nickels
    int nickels = cents / 5;
    cents = cents % 5;
    //cout << "Leftover cents: " << cents << "\n\n";

    //pennies
    int pennies = cents;
    //cout << "Leftover cents: " << cents << "\n\n";
    
    //big print statement
    cout << "x" << hundreds << " $100 bills, x" << twenties << " $20 bills, x" << tens << " $10 bills, x" << fives << " $5 bills, x" << ones << " $1 bills, x" << quarters << " quarters, x" << dimes << " dimes, x" << nickels << " nickels, x" << pennies << " pennies." << endl;

    return 0;
}