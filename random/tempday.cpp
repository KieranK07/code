#include <iostream>
using namespace std;

int main() {
    int days;
    cout << "Enter number of days: ";
    cin >> days;
    int temp[days];
    for (int i = 1; i <= days; i++) {
        cout << "Day " << i << ": ";
        cin >> temp[i - 1];
    }
    cout << "Average temperature: ";
    float sum = 0;
    for (int i = 0; i < days; i++) {
        sum += temp[i];
    }
    float average = sum / days;
    cout << average << endl;
    int abvavg = 0;
    for (int i = 0; i < days; i++) {
        if (temp[i] > average) {
            abvavg++;
        }
    }
    cout << "Number of days above average: " << abvavg << endl;
    return 0;
}