#include <iostream>
#include <array>
using namespace std;

int main() {
    //initialize an array of 5 integers with 0 values
    array<int, 5> myArray1 = {};
    
    //array<int, 5> myArray1 = {1,2,3};
    
    //array<int, 5> myArray2 = {1,2,3,4,5,6};
    //print the elements of the array

    for(int i = 0; i < myArray1.size(); i++) {
        cout << myArray1[i] << " ";
    }
}

//for the first example, the code fills the first three slots, and then initializes the rest to 0
//for the second example, the code does not compile because the array is initialized with more elements than its size