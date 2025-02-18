#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node * next;
};
// 1->2->3->null;
void printListElements(Node* node){
    while(node != nullptr){
        cout << node->data << "->";
        node = node->next; 
    }
    cout << "null";
}
void insertAtFront(Node** head, int newValue){
    // Create a new node
    Node* newNode = new Node();
    newNode->data = newValue; 
    // Set the new node to point to the head
    newNode->next = *head;
    // Make the head point to the new node
    *head = newNode;

}
void insertAtTail(Node** head, int newValue){
    // Create a new node
    Node* newNode = new Node();
    newNode->data = newValue; 
    // This will become the tail node, and tail points to null
    newNode->next = nullptr;
    // Empty list
    if(*head == nullptr){
        *head = newNode;
        return;
    }
    // List with multiple nodes
    // Propagate the list to find the last node
    Node* last = *head;
    while(last->next != nullptr){
        last = last->next;
    }
    // Add the new node to the end of the last node
    last->next = newNode;
}
void insertAfterSpecific(Node* previous, int newValue){
    if(previous == nullptr){
        cout << "Previous node cannot be null." << endl;
        return;
    }
    // Create a new node
    Node* newNode = new Node();
    newNode->data = newValue;
    newNode->next = previous->next;
    previous->next = newNode;
}
void deleteFrontNode(Node** head){
    // Check if the list is empty
    if(*head == nullptr){
        cout << "List is empty. Can't delete head node." << endl;
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    delete temp;
}
void deleteEndNode(Node** head){
    // Check if the list is empty
    if(*head == nullptr){
        cout << "List is empty. Can't delete tail node." << endl;
        return;
    }
    // Single node
    if((*head)->next == nullptr){
        delete *head;
        *head = nullptr;
        return;
    }
    // Multiple Nodes:
    Node* last = *head;
    Node* secondLast = nullptr;
    while(last->next != nullptr){
        secondLast = last;
        last = last->next;
    }
    delete last;
    secondLast->next = nullptr;
}
void deleteSpecificNodeWithTarget(Node** head, int target){
    // Check if the list is empty
    if(*head == nullptr){
        cout << "List is empty. Can't delete target node." << endl;
        return;
    }
    // Head is the target node
    if((*head)->data == target){
        Node* temp = *head;
        (*head) = (*head)->next;
        delete temp;
        return;
    }
    // Two pointer approach
    Node* curr = *head;
    Node* prev = nullptr;
    while (curr != nullptr && curr->data != target)
    {
        prev = curr;
        curr = curr->next;
    }
    // The target is not present in the list, then curr will be null
    if(curr == nullptr){
        cout << "Target not found...!!!" << endl;
    }
    prev->next = curr->next;
    delete curr;

}
int main(){
    // Manual creation of linked list: 1->2->3->null
    // Node* head = new Node();
    // head->data = 1;
    // Node* second = new Node();
    // second->data = 2;
    // Node* third = new Node();
    // third->data = 3;
    // head->next = second;
    // second->next = third;
    // third->next = nullptr;
    Node* head = nullptr;
    insertAtFront(&head, 3);
    insertAtFront(&head, 2);
    insertAtFront(&head, 0);
    printListElements(head);
    cout << endl;
    int arr[] = {4,5,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<size; i++){
        insertAtTail(&head, arr[i]);
    }
    printListElements(head);
    cout << endl;
    insertAfterSpecific(head, 1);
    printListElements(head);
    cout << endl;
    insertAfterSpecific(nullptr, 2);
    cout << "List before deleting the head: " << endl;
    printListElements(head);
    deleteFrontNode(&head);
    cout << endl;
    cout << "List after deleting the head: " << endl;
    printListElements(head);
    cout << endl;

    cout << "List before deleting the tail: " << endl;
    printListElements(head);
    deleteEndNode(&head);
    cout << endl;
    cout << "List after deleting the tail: " << endl;
    printListElements(head);
    cout << endl;

    int target;
    cout << "Enter a target value:" << endl;
    cin >> target;

    deleteSpecificNodeWithTarget(&head, target);

    printListElements(head);
    return 0;
}