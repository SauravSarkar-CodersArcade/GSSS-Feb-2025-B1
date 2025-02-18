#include <iostream>
using namespace std;

int main(){
    int arr[] = {21,12,23,54,25,56,87,0,2,3,1};

    // Formula for finding dynamic size of an array
    int size = sizeof(arr) / sizeof(arr[0]); // 11x4=44  44 / 4 = 11 
    
    cout << arr[4] << endl; 
    for (int i=0; i < size; i++){
        cout << arr[i] << " ";
    } 
    cout << endl;
    // Important question:  
    cout << *(arr+3) << endl;

    // The for-each loop
    for (int x : arr){
        cout << x << " ";
    }
    return 0;
}