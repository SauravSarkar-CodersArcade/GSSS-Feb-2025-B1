#include <iostream>
using namespace std;
class TreeNode {
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr){}
};
bool areIdentical(TreeNode* tree1, TreeNode* tree2){ 
    // Empty
    if(tree1 == nullptr && tree2 == nullptr){
        return true;
    }
    // One of them is null
    if(tree1 == nullptr || tree2 == nullptr){
        return false;
    }
    // Compare the root node data
    if(tree1->data != tree2->data){
        return false;
    }
    // Recursive check for the left & right subtrees of tree1 & tree2
    return (areIdentical(tree1->left, tree2->left) && 
            areIdentical(tree1->right, tree2->right));
}
int main(){
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);
    tree1->left->left = new TreeNode(4);
    tree1->right->right = new TreeNode(5);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);
    tree2->left->left = new TreeNode(4);
    tree2->right->right = new TreeNode(5);

    if(areIdentical(tree1, tree2)){
        cout << "Trees T1 & T2 are identical." << endl;
    }else{
        cout << "Trees T1 & T2 are not identical." << endl;
    }
    return 0;
}