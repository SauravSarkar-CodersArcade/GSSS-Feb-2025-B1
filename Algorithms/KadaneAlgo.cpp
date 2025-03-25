#include <iostream>
using namespace std;
int kadaneAlgo(int arr[], int n){
    int cmax = arr[0];
    int gmax = arr[0];
    for(int i=1; i<n; i++){
        cmax = max(arr[i], cmax + arr[i]);
        gmax = max(cmax, gmax);
    }
    return gmax;
}
int main(){
    int arr[] = {5,-8,1,2,-1,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << kadaneAlgo(arr,n);
    return 0;
}