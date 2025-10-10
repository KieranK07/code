#include <iostream>
#include <vector>
using namespace std;


//doubling function
void doubleValues(vector<unsigned int>& vectorToBeDoubled) {
    //double each value in the vector
    for(int i = 0; i < vectorToBeDoubled.size(); i++) {
        vectorToBeDoubled[i] *= 2;
    }

    return;
}



int main() {
    int input = 0;
    vector<unsigned int> vectorToBeDoubled;

    //input loop
    while(input != -1) {
        cout << "Enter an unsigned integer (-1 to quit): ";
        cin >> input;
        //store input in vector
        if(input != -1 && input >= 0) {
            vectorToBeDoubled.push_back(input);
        } else if(input < -1) {
            cout << "Nurrrp wrong type of numbero" << endl;
        }
    }

    //call doubling function
    doubleValues(vectorToBeDoubled);
    cout << "Doubled values: ";
    for(int i = 0; i < vectorToBeDoubled.size(); i++) {
        cout << vectorToBeDoubled[i] << " ";
    }
    cout << endl;
    return 0;

}