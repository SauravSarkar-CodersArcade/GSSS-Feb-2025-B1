#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};
int findHeight(Node* root){
    // If the tree is empty what will be the height? 0
    if (root == nullptr) return 0;
    int leftHeight = findHeight(root->left);
    int rightheight = findHeight(root->right);
    return max(leftHeight, rightheight) + 1; // We add 1 because we have to take the root
}
int main() {
	Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->right->right->right = new Node(10);
    cout << "Height of the tree: " << findHeight(root) << endl;
}
