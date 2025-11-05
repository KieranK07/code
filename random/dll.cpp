#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* index = nullptr;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        Node* newNode = new Node{value, nullptr, nullptr};

        if (!head)
            head = tail = newNode;
        else {
           //logic
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    cout << "\nDoubly Linked List: ";
    
    while (index) {
        cout << index->data << " <-> ";
        index = index->next;
    }
    cout << "done\n";



    return 0;
}
