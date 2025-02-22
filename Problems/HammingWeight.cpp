#include <iostream>
using namespace std;
int hammingWeight(int n){
    // Write your code here
    int count = 0;
    while(n > 0){
        if(n & 1){
            count++;
        }
        n = n >> 1;
    }return count;
}
int main(){
    cout << "The hamming weight of 11 is: " << hammingWeight(11) << endl;
    cout << "The hamming weight of 0 is: " << hammingWeight(0) << endl;
    cout << "The hamming weight of 5 is: " << hammingWeight(5) << endl;
    return 0;
}