#include <iostream>
#include <vector>
using namespace std;
class Solution {
    private:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans){
        // Base case : When the index is equal to the array or greater, we get an output
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }
        // Exclude
        solve(nums, output, index+1, ans); // Skip the current value and incrememt the index
        // Include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans); // Store the value & increment the index
    }
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> output;
            int index = 0;
            solve(nums, output, index, ans);
            return ans;
        }
    };

int main(){
    
    return 0;
}