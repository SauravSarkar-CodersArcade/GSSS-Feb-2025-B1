#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int arr[7] = {21,12,23,54,25}; // 21,12,23,54,25,0,0
    cout << arr[6] << endl; 
    // Dynamic Memory Allocation
    // C -> malloc, calloc, realloc, free -> stdlib.h
    // C + modifications = C++ (malloc, calloc, realloc, free) -> cstdlib
    // new & delete C + C++ -> Java (JVM -> Handles Garbage Collection)
    int n;
    cout << "Enter the size:" << endl;
    cin >> n;
    // 1 Dimensional Array
    int * myArray = new int[n];

    for (int i=0; i<n; i++){
        cin >> arr[i]; 
    }
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    int ** twoDArray = new int * [n];
    // De-allocate: 
    delete[]myArray;
    delete[]twoDArray;
    return 0;
}