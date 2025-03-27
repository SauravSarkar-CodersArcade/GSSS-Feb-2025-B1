#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class Solution {
    public:
        static string largestNumber(vector<int>& nums) {
        // Convert integers to strings 
        vector<string> strNums;
        for(int num : nums){
            strNums.push_back(to_string(num));
        }    
        // {10, 2} -> {"10", "2"};  
        // Customised sorting
        sort(strNums.begin(), strNums.end(), [](string &a, string &b){
            return a+b > b+a;
        });
        // After sorting if the largest number is 0
        if(strNums[0] == "0") return "0";
        // {"2", "10"};
        // Concatenation
        string result;
        for(string &s : strNums){
            result += s;
        }  
        return result;
    }
};
int main(){
    vector<int> nums = {10,2};
    cout << Solution::largestNumber(nums) << endl;
}