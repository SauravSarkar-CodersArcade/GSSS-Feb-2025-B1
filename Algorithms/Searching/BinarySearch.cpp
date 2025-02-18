#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int key){
     // Write your code here
     int s = 0;
     int e = size - 1;
     int mid = s + (e-s)/2;
     // Base Condition 's' will be less than or equal to 'e'
     while (s <= e){
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid] < key){
            // Shift the 's' to the right side
            s = mid + 1;
        }else{
            // Shift the 'e' to the left side
            e = mid - 1;
        }
        mid = s + (e-s)/2;
     }
     return -1;
}
int main(){
    int arr[] = {2,8,10,15,19,23,37};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index1 = binarySearch(arr, size, 23);
    cout << index1 << endl;
    int index2 = binarySearch(arr, size, 8);
    cout << index2 << endl;
    int index3 = binarySearch(arr, size, 100);
    cout << index3 << endl;
    return 0;
}