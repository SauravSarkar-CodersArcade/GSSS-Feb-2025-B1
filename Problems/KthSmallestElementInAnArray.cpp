#include <bits/stdc++.h>
using namespace std;
int kthSmallestElement(vector<int> arr, int k){
    priority_queue<int> maxHeap;
    for(int num : arr){
        maxHeap.push(num);
        if(maxHeap.size() > k){
            maxHeap.pop(); // Remove the largest element till we reach k
        }
    }
    return maxHeap.top();
}
int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << "Kth smallest element: " << kthSmallestElement(arr, k) << endl;
}
