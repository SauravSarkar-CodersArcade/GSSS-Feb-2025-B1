#include <bits/stdc++.h>
#include <queue>
#include <stack>
using namespace std;
void printQueueElements(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
queue<int> reverseQueue(queue<int>& q){
    stack<int> s;
    // Empty the queue, push all elements to the stack
    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }
    // Empty the stack, push all elements to the queue
    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
}
int main(){
    queue<int> numbers;
    numbers.push(1);
    numbers.push(11);
    numbers.push(12);
    numbers.push(21);
    numbers.push(14);
    cout << "Original Queue Elements: " << endl;
    printQueueElements(numbers);
    reverseQueue(numbers);
    cout << "Reversed Queue Elements: " << endl;
    printQueueElements(numbers);
    return 0;
}