#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// digitExtration extracts the 4 digits from the time string
int digitExtration(string time, int position) {
    return time[position] - '0';
}

// timeCheck checks if the time is valid and returns true or false
bool timeCheck(int a, int b, int c, int d) {
    if (a < 0 || a > 2) return false;
    if (a == 2 && b > 3) return false;
    if (b < 0 || b > 9) return false;
    if (c < 0 || c > 5) return false;
    if (d < 0 || d > 9) return false;
    return true;
}

// timePermutations generates all valid time permutations
void timePermutations(int a, int b, int c, int d, int depth, vector<string>& results) {
    if (depth == 4) {
        if (timeCheck(a, b, c, d)) {
            string validTimes = to_string(a) + to_string(b) + ":" + to_string(c) + to_string(d);
            // save valids to string
            results.push_back(validTimes);
        }
        return;

    }
    // first level of recursion
    if (depth == 0) {
        timePermutations(a, b, c, d, 1, results);
        timePermutations(b, a, c, d, 1, results);
        timePermutations(c, b, a, d, 1, results);
        timePermutations(d, b, c, a, 1, results);
    }
    // second level of recursion
    else if (depth == 1) {
        timePermutations(a, b, c, d, 2, results);
        timePermutations(a, c, b, d, 2, results);
        timePermutations(a, d, c, b, 2, results);
    }
    // third level of recursion
    else if (depth == 2) {
        timePermutations(a, b, c, d, 3, results);
        timePermutations(a, b, d, c, 3, results);
    }
    // fourth level of recursion
    else if (depth == 3) {
        timePermutations(a, b, c, d, 4, results);
    }
}

int main() {
    string inputTime;
    cout << "Enter time: ";
    cin >> inputTime;
    int a = digitExtration(inputTime, 0);
    int b = digitExtration(inputTime, 1);
    int c = digitExtration(inputTime, 2);
    int d = digitExtration(inputTime, 3);
    cout << "Digits are: ";
    cout << a << " " << b << " " << c << " " << d << endl;
    // define whatever tf a vector is
    vector<string> results;

    timePermutations(a, b, c, d, 0, results);

    // Remove duplicate "00:00" entries if present
    if (!results.empty() && results.front() == "00:00") {
        results.erase(remove(results.begin(), results.end(), "00:00"), results.end());
        results.insert(results.begin(), "00:00");
    }
    
    // all valid times
    cout << "All valid times: \n";
    for (const string& time : results) {
        cout << time << "\n";
    }
    
    // total number of valid times
    cout << "Total valid times: " << results.size() << "\n";
    // ERROR CASE
    if (results.size() == 0) {
        cout << "No valid times possible\n";
        return 0;
    } else {
        // sort validTimes so that the earliest is at the front and latest at the back
        sort(results.begin(), results.end());
    }

    

    cout << "Earliest: " << results.front() << "\n";
    cout << "Latest: " << results.back() << "\n";
    return 0;
}