//given a specific node at the top of a recursive tree, use a recurisive function to traverse the tree and search for a specific value
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

//hard coded tree, read left to right from top to bottom
vector<int> values = {30,20,15,100,50,71,17,2,4,47,46,23,7,1,5};

//create the tree from the hard coded values function
// this function should create a balanced binary search tree using the values vector without manual insertion
Node* buildTree(const vector<int>& vals, int start, int end) {
    if (start > end) {
        return nullptr;
    }
    // build from left to right, starting with the top node
    //dont start with the middle value
    
    return node;
}

// search the tree function
bool searchTree(Node* node, int target) {
    if (node == nullptr) {
        return false;
    }
    if (node->value == target) {
        return true;
    }
    //recurisify it
    return searchTree(node->left, target) || searchTree(node->right, target);
}

//print the tree and highlight the target value if found
void printTree(Node* node, int target, string prefix = "", bool isLeft = true) {
    if (node != nullptr) {
        cout << prefix;

        cout << (isLeft ? "├──" : "└──" );

        // highlight target value
        if (node->value == target) {
            cout << "[" << node->value << "]" << endl;
        } else {
            cout << node->value << endl;
        }

        printTree(node->left, target, prefix + (isLeft ? "│   " : "    "), true);
        printTree(node->right, target, prefix + (isLeft ? "│   " : "    "), false);
    }
}

int main() {
    Node* root = buildTree(values, 0, values.size() - 1);
    int target = 71;
// if found in the tree
    if (searchTree(root, target)) {
        cout << "Value " << target << " found in the tree." << endl;
    } else { // if not found in the tree
        cout << "Value " << target << " not found in the tree." << endl;
    }
    cout << "Tree structure:" << endl;
    printTree(root, target);

    return 0;
}