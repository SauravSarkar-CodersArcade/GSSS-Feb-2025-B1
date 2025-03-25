#include <iostream>
using namespace std;
int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int count = 0;
    for(int i=s+1; i <= e; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
    // Place the pivot at it's correct position 
    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);
    // Let's manage the left & right part of the pivot
    // Anything less than pivot goes to the left
    // Anything greater than pivot goes to the right
    int i = s;
    int j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if( i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(int arr[], int s, int e){
    // base case
    if ( s >= e){
        return;
    }
    // Pivot for partition
    int p = partition(arr, s, e);
    // Sort the left part
    quickSort(arr, s, p-1);
    // Sort the right part
    quickSort(arr, p+1, e);
}
int main(){
    int arr[] = {3,1,2,5,8,7,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}