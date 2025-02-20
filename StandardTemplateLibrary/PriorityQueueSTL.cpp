#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    // Search(Max/Min) & Deletion Time Complexity In a Heap (Priority Queue)-> O(1) Constant
    // Max Heap
    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(1);
    maxHeap.push(8);
    maxHeap.push(11);
    maxHeap.push(5);
    maxHeap.push(4);
    cout << "Max Heap: ";
    while(!maxHeap.empty()){
        cout << maxHeap.top() << " ";
        maxHeap.pop(); 
    } 
    cout << endl;

    // For min heap we use a Comparator (function) greater<int>
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(20);
    minHeap.push(2);
    minHeap.push(0);
    minHeap.push(40);
    minHeap.push(10);
    cout << "Min Heap: ";
    while(!minHeap.empty()){
        cout << minHeap.top() << " ";
        minHeap.pop(); 
    } 
    cout << endl;
    return 0;
}