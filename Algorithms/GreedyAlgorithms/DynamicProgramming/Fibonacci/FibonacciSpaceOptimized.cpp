#include <iostream>
using namespace std;
int fibonacciSpaceOptimized(int n){
    int p2 = 0;
    int p1 = 1;
    if(n == 0){
        return p2;
    }else if(n == 1){
        return p1;
    }
    for(int i=2; i<=n; i++){
        int curr = p2 + p1;
        p2 = p1;
        p1 = curr;
    }
    return p1;
}
int main(){
    int n;
    cin >> n;
    cout << fibonacciSpaceOptimized(n) << endl;
    return 0;
}