#include <bits/stdc++.h>
using namespace std;
int fibonacciTab(int n){
    // Step 1
    // Create the dp array
    vector<int> dp(n+1, -1);
    // Step 2: Store the known values
    dp[0] = 0;
    dp[1] = 1;
    // Step 3: Calculate the rest of the values from 2 to n (Unknown Values)
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    } 
    return dp[n];
}
int main(){
    int n;
    cin >> n;
    cout << fibonacciTab(n) << endl;
    return 0;
}