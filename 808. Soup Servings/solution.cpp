#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    double helpFunc(int n, int m, unordered_map<int, unordered_map<int, double>>& dp){
        // cout << dp[max(0, n - 4)][m] << endl;
        // cout << dp[max(0, n - 3)][max(0, m - 1)] << endl;
        // cout << dp[max(0, n - 2)][max(0, m - 2)] << endl;
        // cout << dp[max(0, n - 1)][max(0, m - 3)] << endl;

        return 0.25 * (dp[max(0, n - 4)][m] +
                      dp[max(0, n - 3)][max(0, m - 1)] +
                      dp[max(0, n - 2)][max(0, m - 2)] + 
                      dp[max(0, n - 1)][max(0, m - 3)]);
    }

    double soupServings(int n) {
        int portion = ceil((double) n/25);
        unordered_map<int, unordered_map<int, double>> dp;
        dp[0][0] = 0.5;
        for (int i = 1; i <= portion; ++i){
            dp[0][i] = 1; dp[i][0] = 0;

            for (int j = 1; j <= i; ++j){
                dp[j][i] = helpFunc(j, i, dp);
                dp[i][j] = helpFunc(i, j, dp);
            }

            if (dp[i][i] > 1 - 1e-5){ // Since we get too close to 1, there is no reason to check other i's
                return 1;
            }
        }

        return dp[portion][portion];
    }
};

int main(){
    Solution test;

    cout << test.soupServings(1) << endl;
    cout << test.soupServings(25) << endl;
    cout << test.soupServings(50) << endl;
    cout << test.soupServings(100) << endl;
}