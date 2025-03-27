#include <bits/stdc++.h>
using namespace std;
void findTwoUniqueElements(int arr[], int n){
    int xorAll = 0;
    for(int i=0; i<n; i++){
        xorAll ^= arr[i];
    }
    int rightMostSetBit = xorAll & -xorAll;
    int num1 = 0, num2 = 0;
    for(int i=0; i<n; i++){
        if(arr[i] & rightMostSetBit){
            num1 ^= arr[i];
        }else{
            num2 ^= arr[i];
        }
    }
    cout << "The unique elements: " << num1 << "," << num2 << endl;
}
int main() { // Time Complexity O(n) -> Linear
    int arr[] = {1,2,3,4,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    findTwoUniqueElements(arr, size);
    return 0;
}
