#include <bits/stdc++.h>
using namespace std;
void printNGE(int arr[], int n){
    stack<int> s;
    s.push(arr[0]); // Push the first element onto the stack

    for(int i=1; i<n; i++){
        // While stack is not empty and the top element is smaller than arr[i]
        while(!s.empty() && s.top() < arr[i]){
            cout << s.top() << " --> " << arr[i] << endl;
            s.pop();
        }
        s.push(arr[i]); // Push the current element onto the stack
    }
    // Remaining elements in the stack have no greater element in future
    while(!s.empty())
    {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}
int main(){
    int arr[] = {4,5,2,25};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}