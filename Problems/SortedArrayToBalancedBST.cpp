#include <iostream>
using namespace std;
class TreeNode {
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr){}
};
TreeNode* sortedArrayToBalancedBST(int arr[], int s, int e){
    // Start exceeds End ?
    if( s > e){
        return nullptr;
    }
    int mid = s + (e-s)/2;
    TreeNode* root = new TreeNode(arr[mid]);
    // Recursive call for the left side of the array
    root->left = sortedArrayToBalancedBST(arr, s, mid-1);
    // Recursive call for the right side of the array
    root->right = sortedArrayToBalancedBST(arr, mid+1, e);
    return root;
}
void inOrderTraversal(TreeNode* root){
    if(root != nullptr){
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode* root = sortedArrayToBalancedBST(arr, 0, n-1);
    cout << "In-Order Traversal: ";
    inOrderTraversal(root); 
    cout << endl;
    return 0;
}