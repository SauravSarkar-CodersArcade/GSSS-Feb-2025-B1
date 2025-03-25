#include <iostream>
using namespace std;  // Armstrong Number 153 = 1^3 + 5^3 + 3^3 = 1+125+27 = 153
int reverseInteger(int n){
    int ans = 0;
    while (n != 0)
    {
        int digit = n % 10;
        ans = ans * 10 + digit;
        n = n / 10;
    }
    return ans;
}
int main(){
    cout << reverseInteger(123) << endl;
    cout << reverseInteger(120) << endl;
    return 0;
}