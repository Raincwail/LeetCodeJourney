#include "../printSmth.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // dp initialization
        vector<int> dp (nums.size(), 1);
        vector<int> ways (nums.size(), 1);

        for (int i = 0; i < dp.size(); ++i){
            for (int j = i - 1; j >= 0; --j){
                //dp update
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]){ 
                        dp[i] = dp[j] + 1;
                        ways[i] = ways[j];
                    } else if (dp[j] + 1 == dp[i]){
                        ways[i] += ways[j];
                    }
                }
            }
        }

        int maxi = *max_element(dp.begin(), dp.end());

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (dp[i] == maxi) {
                ans = ans + ways[i]; 
            }
        }
        return ans;
    }
};


int main(){
    vector<int> test_case_1 = {1,3,5,4,7};
    vector<int> test_case_2 = {2,2,2,2,2};
    
    Solution test;

    cout << test.findNumberOfLIS(test_case_1) << endl;
    cout << test.findNumberOfLIS(test_case_2) << endl;
}