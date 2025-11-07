#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "List is empty." << endl;
        return 0;
    }

    Node* head = nullptr;
    Node* tail = nullptr;
    Node* index = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        Node* newNode = new Node{value, nullptr, nullptr};

        if (!head)
            head = newNode;
        else
            tail->next = newNode;
            newNode->prev = tail;

        tail = newNode;
    }

    cout << "\nDoubly linked list contents:\n";
    index = head;
    while (index) {
        cout << index->data << " ";
        index = index->next;
    }
    cout << endl;

    //insert another node at location num
    int num, val;
    cout << "Enter the location to insert a new node: ";
    cin >> num;
    cout << "Enter the value for the new node: ";
    cin >> val;
    Node* newNode = new Node{val, nullptr, nullptr};
    if (num == 0) {
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
    } else {
        index = head;
        for (int i = 0; i < num - 1 && index; i++) {
            index = index->next;
        }
        if (index) {
            newNode->next = index->next;
            newNode->prev = index;
            if (index->next) index->next->prev = newNode;
            index->next = newNode;
        } else {
            cout << "Position out of bounds." << endl;
            delete newNode;
        }
    }

        cout << "\nDoubly linked list contents NEW:\n";
    index = head;
    while (index) {
        cout << index->data << " ";
        index = index->next;
    }
    cout << endl;

    // Free memory
    index = head;
    while (index) {
        Node* temp = index;
        index = index->next;
        delete temp;
    }

    return 0;
}
