#include <iostream>
using namespace std;
int recursive_binary_search(int * arr, int n, int s, int e, int key){
    // Base condition s <= e
    if (s <= e){
        int mid = s + (e-s)/2;
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid] < key){
            // Shift the 's' to the right side because it changes
            return recursive_binary_search(arr,n,mid+1,e,key);
        }else{
            // Shift the 'e' to the left side because it changes
            return recursive_binary_search(arr,n,s,mid-1,key);
        }
     }
     return -1;
}
int main(){
    int arr[] = {2,8,10,15,19,23,37};
    int n = sizeof(arr) / sizeof(arr[0]);
    int index1 = recursive_binary_search(arr, n, 0, n-1, 23);
    cout << index1 << endl;
    int index2 = recursive_binary_search(arr, n, 0, n-1, 8);
    cout << index2 << endl;
    int index3 = recursive_binary_search(arr, n, 0, n-1, 100);
    cout << index3 << endl;
    cout << "Integer Max: " << INT_MAX << endl;
    cout << "Integer Min: " << INT_MIN << endl;
    cout << INT_MAX + 1 << endl; // Min
    cout << INT_MIN - 1 << endl; // Max
    return 0;
}