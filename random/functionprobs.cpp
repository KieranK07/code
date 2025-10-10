#include <iostream>
using namespace std;

bool divides(int a, int b) {
    return b % a == 0;
}

int exp(int b, int e) {
    //figure out way to do exponential
    int final = b;
    for(int i=1; i<e; i++){
        final = final*b;
    }
    return final;
}

int fib(int n) {
    int output;
    if (n==0||n==1){
        cout << endl;
        return 1;
    }
    else if (n>1) {
        int fib1 = fib(n-1);
        int fib2 = fib(n-2);

        output = fib1 + fib2;
        cout << output << "  ";
    }
    return output;
}

int main() {
    fib(20);
}