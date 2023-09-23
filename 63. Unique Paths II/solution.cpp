#include "../printSmth.h"
#include <vector>
#include <iostream>

using namespace std;
using ll = long long;

class Solution {
public:
    vector<vector<int>> dp_rec;
    vector<vector<int>> obGrid;

    int uniquePathsWithObstacles_iter(vector<vector<int>>& obstacleGrid) {
        auto m = obstacleGrid.size();
        auto n = obstacleGrid[0].size();

        if (m == 1 && n == 1){
            return obstacleGrid[0][0] == 1 ? 0 : 1;
        }

        vector<vector<ll>> dp(m + 1, (vector<ll>(n + 1, 0)));

        dp[1][1] = 0;
        
        if (n > 1 && obstacleGrid[0][0] != 1) {
            dp[1][2] = obstacleGrid[0][1] != 1 ? 1 : 0;
        }

        if (m > 1 && obstacleGrid[0][0] != 1){
            dp[2][1] = obstacleGrid[1][0] != 1 ? 1 : 0;
        }

        for (int i = 1; i < m + 1; ++i){
            for (int j = 1; j < n + 1; ++j){
                if (obstacleGrid[i - 1][j - 1] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                if (dp[i][j] != 0) {
                    continue;
                }

                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m][n];
    }

    int helpFunc(int i, int j){
        if (obGrid[i][j] == 1){
            return 0;
        }

        if (i + j == 0) {
            return 1;
        }

        if (dp_rec[i][j] != -1){
            return dp_rec[i][j];
        }

        dp_rec[i][j] = (i > 0 ? helpFunc(i - 1, j) : 0) + (j > 0 ? helpFunc(i, j - 1) : 0);

        return dp_rec[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        auto m = obstacleGrid.size();
        auto n = obstacleGrid[0].size();
        
        dp_rec = vector<vector<int>> (m, (vector<int>(n, -1)));
        obGrid = obstacleGrid;

        return helpFunc(m - 1, n - 1);;
    };  
};

int main(){
    vector<vector<int>> test_case_1 = {{0, 0, 0},
                                       {0, 1, 0},
                                       {0, 0, 0}};
    vector<vector<int>> test_case_2 = {{1, 1},
                                       {0, 0}};
    vector<vector<int>> test_case_3 = {{0, 0, 0}};

    Solution test;

    // cout << test.uniquePathsWithObstacles(test_case_1) << endl;
    cout << test.uniquePathsWithObstacles(test_case_2) << endl;
    // cout << test.uniquePathsWithObstacles(test_case_3) << endl;
};