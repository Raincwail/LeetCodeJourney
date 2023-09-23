#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        
        dp[0] = 1;

        for (int i = 1; i <= target; ++i){
            for (const auto el : nums){
                if (i - el >= 0)
                    dp[i] += dp[i - el];
            }
        }

        return dp[target];
    } 
};

int main(){
    vector<int> test_case_1 = {1, 2, 3};
    vector<int> test_case_2 = {9};
    Solution test;

    cout << test.combinationSum4(test_case_1 , 4) << endl;
    cout << test.combinationSum4(test_case_2, 4) << endl;
}