#include <bits/stdc++.h>
#include <queue>
using namespace std;
void printQueueElements(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
int main(){
    // front, back, push, pop, size, empty
    queue<int> numbers;
    numbers.push(1);
    numbers.push(11);
    numbers.push(12);
    numbers.push(21);
    numbers.push(14);

    cout << "Front element: " << numbers.front() << endl;
    cout << "Back/Rear element : " << numbers.back() << endl;
    printQueueElements(numbers);
    return 0;
}