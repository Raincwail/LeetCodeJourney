#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int s1_size = text1.size() - 1;
        int s2_size = text2.size() - 1;

        vector<vector<int>> dp(s1_size + 1, vector<int>(s2_size + 1, -1));

        for (int i = s1_size; i >= 0; i--){
            for (int j = s2_size; j >= 0; j--){
                if (text1[i] == text2[j]){
                    dp[i][j] = (i + 1 <= s1_size && j + 1 <= s2_size) ? dp[i + 1][j + 1] + 1 : 1;
                } else {
                    dp[i][j] = max(
                        (i + 1 <= s1_size) ? dp[i + 1][j] : 0,
                        (j + 1 <= s2_size) ? dp[i][j + 1] : 0
                    );
                }
            }
        }

        // for (auto vec: dp){
        //     for (auto el: vec){
        //         cout << el << ' ';
        //     }
        //     cout << endl;
        // }

        return dp[0][0];
    }
};

int main(){
    Solution test;

    std::cout << test.longestCommonSubsequence("abcde", "ace") << endl;
    std::cout << test.longestCommonSubsequence("abc", "abc") << endl;
    std::cout << test.longestCommonSubsequence("abc", "def") << endl;
}