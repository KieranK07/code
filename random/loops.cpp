#include <iostream>
#include <random>
#include <thread>
using namespace std;

int main() {
    string target = "Hello, World!";
    string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789, !";
    mt19937 gen(random_device{}());
    uniform_int_distribution<> dis(0, charset.size() - 1);

    string current(target.size(), ' ');
    cout << current << endl;

    for (size_t i = 0; i < target.size(); ++i) {
        char c;
        do {
            c = charset[dis(gen)];
            current[i] = c;
            cout << "\r" << current << flush;
            this_thread::sleep_for(chrono::milliseconds(20));
        } while (c != target[i]);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << endl;
}
