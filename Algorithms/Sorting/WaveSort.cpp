#include <iostream>
#include <algorithm>
using namespace std;
void waveSort(int arr[], int n){ 
    sort(arr, arr + n); // first, last  O(n log n)
    for(int i=0; i<n-1; i = i+2){ // O(n) 
        swap(arr[i], arr[i+1]);
    } // Total O(n) + O(n log n)
}
int main(){
    int arr[] = {10,90,49,2,1,5,23};
    int n = sizeof(arr) / sizeof(arr[0]);
    waveSort(arr, n);
    for (int x : arr){
        cout << x << " ";
    }cout << endl;
    return 0;
}