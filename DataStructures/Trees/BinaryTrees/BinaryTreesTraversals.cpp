#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = right = nullptr;
    }
};
// DFS Traversal using recursion 
void preOrderTraversal(Node* root){ // DLR
    if(root != nullptr){
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void inOrderTraversal(Node* root){ // LDR
   if(root != nullptr){
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
   }
}
void postOrderTraversal(Node* root){ // LRD
    if(root != nullptr){
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
    }
}
int main(){
    // Start the construction from top to bottom & left to right
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(9);
    root->right->right->left = new Node(15);

    cout << "Pre-Order Traversal: ";
    preOrderTraversal(root); 
    cout << endl;

    cout << "In-Order Traversal: ";
    inOrderTraversal(root); 
    cout << endl;

    cout << "Post-Order Traversal: ";
    postOrderTraversal(root); 
    cout << endl;
    return 0;
}