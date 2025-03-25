#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void kLargestElements(vector<int> arr, int k){
    priority_queue<int, vector<int>, greater<int>> minHeap; 
    for(int num : arr){
        minHeap.push(num);
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }
    // Print the K largest elements
    while (!minHeap.empty())
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }cout << endl;
}
main(){
    vector<int> arr = {20,10,30,40,60,50};
    int k = 3;
    kLargestElements(arr, k);
    return 0;
}