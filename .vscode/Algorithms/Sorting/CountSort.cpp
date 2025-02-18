#include <iostream>
using namespace std;
void countSort(int arr[], int size){
    // Find the max
    int k = arr[0];
    for (int i=1; i<size; i++){
        if(arr[i] > k){
            k = arr[i];
        }
    }
    // Create a count array (0 to max)
    int count[10] = {0}; // How many single digit elements ? 0-9 (ten)
    // Calculate the frequency of each element in the array
    for(int i=0; i<size; i++){
        count[arr[i]]++;
    }
    // Calculate the cumulative count : 
    // current = cuurent + previous 
    // Moksha [0](Skipped) - Start from index - 1  & go till max 'k'
    for (int i = 1; i <= k; i++) {
        // Current = Current + Previous
        count[i] += count[i-1];
    }
    // Create the output array
    int output[size];
    // Start from the end of the array : R -> L
    for(int i=size-1; i >= 0; i--){
        output[--count[arr[i]]] = arr[i];    
    }

    // Copy the output back to the input
    for(int i=0; i<size; i++){
        arr[i] = output[i];
    }

}
int main(){
    int arr[] = {2,3,1,3,1,4,6,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Before sorting: ";
    for (int x : arr){
        cout << x << " ";
    } 
    countSort(arr, size);
    cout << endl;
    cout << "After sorting: ";
    for (int x : arr){
        cout << x << " ";
    } 
    return 0;
}