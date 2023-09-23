#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:

    // vector<vector<int>> dp;

    // int helpFunc(int ind, int curSum, vector<int>& coins){
    //     if (ind == coins.size()){
    //         return 0;
    //     }

    //     if (curSum == 0){
    //         return 1;
    //     }

    //     if (curSum < 0) {
    //         return 0;
    //     }

    //     if (dp[ind][curSum] != -1){
    //         return dp[ind][curSum];
    //     }

    //     if (coins[ind] > curSum){
    //         return dp[ind][curSum] = helpFunc(ind + 1, curSum, coins);
    //     }


    //     auto l = helpFunc(ind, curSum - coins[ind], coins);
    //     auto r = helpFunc(ind + 1, curSum, coins);

    //     // cout << "l: " << ind << ' ' << curSum - coins[ind] << " res: " << l << endl;
    //     // cout << "r: " << ind + 1 << ' ' << curSum << ' ' << " res: " << r << endl;

    //     dp[ind][curSum] = l + r;

    //     // dp[ind][curSum] = helpFunc(ind, curSum - coins[ind], coins) + helpFunc(ind + 1, curSum, coins);
    //     return dp[ind][curSum]; 
    // }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i] > j) {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - coins[i]];
                }
            }
        }

        for(auto vec:dp){
            for(auto el:vec){
                cout << el << ' ';
            }
            cout <<endl;
        }

        return dp[0][amount];
    
    }
};

int main(){
    vector<int> test_case_1 = {1,2,5};
    vector<int> test_case_2 = {2};
    vector<int> test_case_3 = {10};

    Solution test;
    vector<vector<int>> toPrint;

    cout << test.change(5, test_case_1) << endl;
    cout << test.change(3, test_case_2) << endl;
    cout << test.change(10, test_case_3) << endl;
}