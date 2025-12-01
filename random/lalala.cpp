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

//create the tree from the hard coded values
Node* testTree() {
    Node* root = new Node(values[0]);
    root->left = new Node(values[1]);
    root->right = new Node(values[2]);

    root->left->left = new Node(values[3]);
    root->left->right = new Node(values[4]);

    root->right->left = new Node(values[5]);
    root->right->right = new Node(values[6]);

    root->left->left->left = new Node(values[7]);
    root->left->left->right = new Node(values[8]);

    root->left->right->left = new Node(values[9]);
    root->left->right->right = new Node(values[10]);

    root->right->left->left = new Node(values[11]);
    root->right->left->right = new Node(values[12]);

    root->left->left->left->left = new Node(values[13]);
    root->left->left->left->right = new Node(values[14]);

    return root;
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
    Node* root = testTree();
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