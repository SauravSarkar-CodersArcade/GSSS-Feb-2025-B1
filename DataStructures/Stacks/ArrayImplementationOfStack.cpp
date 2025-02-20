#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
class Stack {
private:
    int arr[MAX_SIZE];
    int top;
public:
    Stack(){
        top = -1;
    }
    bool isFull(){
        return (top == MAX_SIZE - 1);
    }
    void push(int element){
        if(top == MAX_SIZE - 1){
            cout << "Stack Overflow...!!!" << endl;
        }
        top++;
        arr[top] = element;
    }
    void pop(){
        if(top == -1){
            cout << "Stack Underflow..!!" << endl;
        }else{
            top--;
        }
    }
    int peek(){
        if(top == -1){
            cout << "Stack Underflow..!!" << endl;
            return -1;
        }else{
            return arr[top];
        }
    }
    bool isEmpty(){
        return top == -1;
    }
    int size(){
        if(top == -1){
            return top + 1;
        }else{
            return top + 1;
        }
    }
};
int main(){
    
    Stack stack = Stack();
    // Stack stack1;
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i=0; i<size; i++){
        stack.push(arr[i]);
    }
    cout << "Top element of the stack: " << stack.peek() << endl;
    stack.pop();
    cout << "Top element of the stack: " << stack.peek() << endl;
    cout << stack.isEmpty() << endl;
    cout << "Size of the stack: " << stack.size() << endl;
    return 0;
}