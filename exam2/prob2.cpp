// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data = -1;
    Node* next = nullptr;

    Node(int d) : data(d), next(nullptr) {}
    Node() = default;
};

class SLL {
public:
    Node* head;
    Node* index;
    int size = 0;

    SLL(vector<int> myNums) {
        if (myNums.empty()) {
            head = nullptr;
            index = nullptr;
            return;
        }

        // Create first node
        head = new Node(myNums[0]);
        size = 1;
        index = head;

        // Staple on remaining nodes
        for (int i = 1; i < myNums.size(); i++) {
            Node* newNode = new Node(myNums[i]);
            index->next = newNode;
            index = index->next;
            size++;
        }

    }
};

// Print entire list
void printList(const SLL& myList) {
    Node* index = myList.head;
    while (index != nullptr) {
        cout << index->data << " ";
        index = index->next;
    }
    cout << endl;
}

// YOU DO THIS ONE!!!
//Reverse a linked list and return new head
Node* reverseList(Node* headOfList) {
    Node* prev = nullptr;
    Node* current = headOfList;
    Node* next = nullptr;

    while (current != nullptr) {
        // store the node
        next = current->next;
        // reverse 
        current->next = prev;
        // move one ahead
        prev = current;
        current = next;
    }
    return prev; // return the new head
}

int main() {
    // test case 1: 1 2 3 4 5 6 7
    SLL list1({1,2,3,4,5,6,7});
    printList(list1);  //prints the original list.
    list1.head = reverseList(list1.head);
    printList(list1);  //prints the reversed list.
    
    // test case 2: 4 2 1
    SLL list2({4,2,1});
    printList(list2);
    list2.head = reverseList(list2.head);
    printList(list2);

    // test case 3: 5
    SLL list3({5});
    printList(list3);
    list3.head = reverseList(list3.head);
    printList(list3);

    return 0;
}
