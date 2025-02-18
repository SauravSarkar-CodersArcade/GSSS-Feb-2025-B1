#include <iostream>
using namespace std;

int countSteps(int n){
    // Base cases
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 2;
    // Recursive cases
    return countSteps(n-1) + countSteps(n-2);
}
int main(){
    cout << countSteps(4) << endl;
    return 0;
}