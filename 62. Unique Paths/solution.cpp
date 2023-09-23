#include "../printSmth.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (i == 0 && j == 0)
                    continue;

                if (i == 0){
                    dp[i][j] = dp[i][j - 1];
                    continue;
                }

                if (j == 0){
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }

                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                
                // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
            }
        }

        // print2DVec(dp);

        return dp[m - 1][n - 1];
    }
};

int main(){
    Solution test;

    cout << test.uniquePaths(3, 7) << endl;
    cout << test.uniquePaths(3, 2) << endl;
    cout << test.uniquePaths(1, 10) << endl;
}