#include <bits/stdc++.h>
#include <stack>
using namespace std;
void printStackEmements(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main(){
    // push pop size empty top 
    stack<int> numbers;
    numbers.push(1);
    numbers.push(11);
    numbers.push(12);
    numbers.push(21);
    numbers.push(14);
    cout << "Top element: " << numbers.top() << endl;
    numbers.pop();
    cout << "Top element: " << numbers.top() << endl;
    cout << "Stack size: " << numbers.size() << endl;
    printStackEmements(numbers);
    return 0;
}