#include <iostream>
#include<list>
using namespace std;

int main() {
    float num = 0;
    float total = 0; 
    list<int> items;

    cout << "Enter price of item (0 to stop): ";
    cin >> num;
    while (num > 0) {
        items.push_back(num);
        cout << "Enter price of item (0 to stop): ";
        cin >> num;
    }

    /*for (int item : items) {
        cout << item << " ";
    }
    cout << endl;
    */

    cout << "You bought " << items.size() << " items.\n";

    for (int item : items) {
        total = total + item;
    }
    cout << "Total: " << total << endl;

    if (total >= 50) {
        cout << "You get a 10% discount!\n";
        cout << "Discounted total: " << total - (total/10);
    }
    cout << endl;
}