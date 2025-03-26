#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};
class Approach {
    public:
    static bool isPalindrome(Node* head){
        stack<int> s;
        Node* current = head;
        // 1st traversal to push the list nodes into stack
        current = head;
        while (current != nullptr)
        {
            s.push(current->data);
            current = current->next;
        }
        // 2nd traversal to compare nodes with stack elements
        current = head;
        while(current != nullptr){
            int top = s.top();
            s.pop();
            if(current->data != top){
                return false;
            }
            current = current->next;
        }
        return true;
    }
};
int main() {
	Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(11); 
    if (Approach::isPalindrome(head)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
}
