#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;
    int arrLen;
    vector<vector<int>> dp;

    int helpFunc(int ind, int rem){
        if (rem == 0){
            return ind == 0;
        }

        if (dp[ind][rem] != -1){
            return dp[ind][rem];
        }

        int ans = helpFunc(ind, rem - 1);
        if (ind > 0){
            ans = (ans + helpFunc(ind - 1, rem - 1)) % MOD;
        }

        if (ind + 1 < arrLen){
            ans = (ans + helpFunc(ind + 1, rem - 1)) % MOD;
        }

        dp[ind][rem] = ans;
        return ans;
    }

public:
    int numWays(int steps, int arrLen) {
        this->arrLen = min(arrLen, steps);
        dp = vector<vector<int>>(this->arrLen, vector<int>(steps + 1, -1));

        return helpFunc(0, steps);
    }

    int numWays_optimized(int steps, int arrLen){
        this->arrLen = min(arrLen, steps);
        vector<int> dp;
        vector<int> prevDp(this->arrLen, 0);

        prevDp[0] = 1;

        for (int i = 0; i < steps; ++i){
            dp = vector<int>(this->arrLen, 0);
            for (int j = this->arrLen - 1; j >= 0; --j){
                int ans = prevDp[j];

                if (j > 0){
                    ans = (ans + prevDp[j - 1]) % MOD;
                }

                if (j < this->arrLen - 1){
                    ans = (ans + prevDp[j + 1]) % MOD;
                }

                dp[j] = ans;
            }
            prevDp = dp;
        }

        return prevDp[0];
    }
};

int main(){
    Solution test;

    cout << test.numWays_optimized(3, 2) << endl;
}