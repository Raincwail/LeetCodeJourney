#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> dp(nums.size());

        for (int i = 0; i < nums.size(); ++i){
            if (!q.empty() && i - q.front() > k)
                q.pop_front();
            
            dp[i] = (!q.empty() ? dp[q.front()] : 0) + nums[i];
            while (!q.empty() && dp[q.back()] < dp[i])
                q.pop_back();

            if (dp[i] > 0)
                q.push_back(i);
        }

        return *max_element(dp.begin(), dp.end());
    }
};
int main(){
    vector<int> test_case_1 = {10, -2, -10, -5, 20};

    Solution test;

    cout << test.constrainedSubsetSum(test_case_1, 2) << endl;
}