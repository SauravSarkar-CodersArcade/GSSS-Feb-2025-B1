#include <iostream>
using namespace std;
class Node {
    public:
    int value;
    Node* next;
    Node* prev;
};
void forwardTraversal(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->value << "<->";
        temp = temp->next;
    }
    cout << "null" << endl;
}
void backwardTraversal(Node* tail){
    Node* temp = tail;
    while(temp != nullptr){
        cout << temp->value << "<->";
        temp = temp->prev;
    }
    cout << "null" << endl;
}
int main(){
    // null <- 1 <-> 2 <-> 3 <-> 4 -> null
    Node* head;
    Node* tail;
    Node* node = new Node();
    node->value = 1;
    node->next = nullptr;
    node->prev = nullptr;
    head = node;
    tail = node;

    // second
    node = new Node();
    node->value = 2;
    node->next = nullptr;
    node->prev = tail;
    tail->next = node;
    tail = node;
    // third
    node = new Node();
    node->value = 3;
    node->next = nullptr;
    node->prev = tail;
    tail->next = node;
    tail = node;
    //fourth
    node = new Node();
    node->value = 4;
    node->next = nullptr;
    node->prev = tail;
    tail->next = node;
    tail = node;

    // Traversals
    forwardTraversal(head);
    backwardTraversal(tail);
    return 0;
}