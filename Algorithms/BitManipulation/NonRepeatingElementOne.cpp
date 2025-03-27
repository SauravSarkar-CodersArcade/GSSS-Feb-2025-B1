#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1,3,7,2,1,3,2};
    int result = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i=0; i<size; i++){
        result = result ^ arr[i];
    }
    cout << "The non-repeating element is: " << result << endl;
    return 0;

}
