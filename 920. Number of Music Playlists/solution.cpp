#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
         const int modulo = 1e9 + 7;
        vector<vector<long>> dp(goal + 1, vector<long>(n + 1));

        dp[0][0] = 1;

        for (int i = 1; i <= goal; ++i){
            for (int j = 1; j <= min(i, n); ++j){
                dp[i][j] = (dp[i][j] + dp[i-1][j-1] * (n - j + 1)) % modulo;

                if (j > k){
                    dp[i][j] = (dp[i][j] + dp[i-1][j] * (j - k)) % modulo;
                }
            }
        }

        return dp[goal][n];
    }
};

int main(){
    Solution test;

    cout << test.numMusicPlaylists(3, 3, 1) << endl;
    cout << test.numMusicPlaylists(2, 3, 0) << endl;
    cout << test.numMusicPlaylists(2, 3, 1) << endl;
}