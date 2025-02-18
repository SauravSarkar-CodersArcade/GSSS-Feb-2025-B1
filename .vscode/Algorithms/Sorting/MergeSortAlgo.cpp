#include <iostream>
using namespace std;
void merge(int * arr, int s, int e){
    int mid = s + (e-s)/2;
    int l1 = mid - s + 1;
    int l2 = e - mid;
    // Create two arrays for copying the contents of left & right
    // parts of the array
    int * first = new int[l1];
    int * second = new int[l2];
    int k = s;
    for(int i=0; i<l1; i++){
        first[i] = arr[k++];
    }
    k = mid + 1;
    for(int i=0; i<l2; i++){
        second[i] = arr[k++];
    }
    // Two Pointer Approach
    int i = 0;
    int j = 0;
    k = s;
    while(i < l1 && j < l2){
        if(first[i] < second[j]){
            arr[k++] = first[i++];
        }else{
            arr[k++] = second[j++];
        }
    }
    // If any elements are remaining, copy them manually
    while(i < l1){
        arr[k++] = first[i++];
    }
    while(j <l2){
        arr[k++] = second[j++];
    }
    // Delete resources
    delete[]first;
    delete[]second;
}
void mergeSort(int * arr, int s, int e){
    // Base case
    if(s >= e){
        return; 
    }
    int mid = s + (e-s)/2;
    // left part
    mergeSort(arr, s, mid);
    // right part
    mergeSort(arr, mid+1, e);
    // merge
    merge(arr, s, e);
}
int main(){
    int arr[] = {0,-1,-2,3,1,4,6,5,7,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, size-1);
    for(int x : arr){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}