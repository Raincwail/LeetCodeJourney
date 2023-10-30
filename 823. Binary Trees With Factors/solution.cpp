#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, long> dp;

        sort(arr.begin(), arr.end());

        int ans = 0;
        for (int i = 0; i < arr.size(); ++i){
            dp[arr[i]] = 1;
            for (int j = i - 1; j >= 0; --j){
                if (arr[i] % arr[j] == 0){
                    dp[arr[i]] += dp[arr[i] / arr[j]] * dp[arr[j]];
                }
            }
            ans = (ans + dp[arr[i]]) % MOD;
        }

        return ans;
    }
};
int main(){
    vector<int> test_case_1 = {2, 4};

    Solution test;

    cout << test.numFactoredBinaryTrees(test_case_1) << endl;
}