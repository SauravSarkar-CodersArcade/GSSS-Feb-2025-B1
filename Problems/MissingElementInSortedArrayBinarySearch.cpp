#include <iostream>
using namespace std;
int missingElementBinarySearch(int arr[], int n){
    int s = 0;
    int e = n - 1;
    while (s <= e){
        int mid = s + (e-s)/2;
        if(arr[mid] != mid + 1){
            // left side
            if(mid == 0 || arr[mid-1] == mid){
                return mid + 1;
            }
            e = mid -1;
        }else{
            // Right side 
            s = mid + 1;
        }
    }
    return n + 1;
}
int main(){
    int arr1[] = {1,2,3,5,6,7,8};
    cout << missingElementBinarySearch(arr1, 8) << endl;
    int arr2[] = {1,2,3,4,5,6,7};
    cout << missingElementBinarySearch(arr2, 7) << endl;
    return 0;
}