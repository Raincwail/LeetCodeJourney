#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int n, m;
    vector<vector<int>> dp;
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));

        dp[0][0] = nums1[0] * nums2[0];
        for (int j = 1; j < m; ++j){
            dp[0][j] = max(nums1[0] * nums2[j], dp[0][j - 1]);
        }

        for (int i = 1; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (j == 0){
                    dp[i][j] = max(nums1[i] * nums2[j], dp[i - 1][j]);
                    continue;
                }

                int mult = nums1[i] * nums2[j];
                dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), max(mult, mult + dp[i - 1][j - 1]));
            }
        }

        return dp[n - 1][m - 1];
    }
};

int main(){
    vector<int> test_case_1_1 = {2, 1, -2, 5};
    vector<int> test_case_1_2 = {3, 0, -6};

    Solution test;

    cout << test.maxDotProduct(test_case_1_1, test_case_1_2) << endl;
}