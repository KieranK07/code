#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<double> myVector = {1,2,3,4,5,6,7,8};
    for(double& element: myVector){
        element=3*element;
    }
    for(const double& element: myVector){
        cout<<element<<endl;
    }
}

//What went wrong: the elements of the vector dont change bc they wern't passed by reference
//Fix: add & to the for loop variable to pass by reference