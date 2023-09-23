#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    bool helpFunc(string& s1, string& s2, int i, int j, string& s3){
        if (i + j == s3.size()){
            return true;
        }

        if (dp[i][j] != -1){
            return dp[i][j];
        }

        bool resS1 = false, resS2 = false;

        if (i < s1.size() && s1[i] == s3[i + j]){
            resS1 = helpFunc(s1, s2, i+1, j, s3);
        }

        if (j < s2.size() && s2[j] == s3[i + j]){
            resS2 = helpFunc(s1, s2, i, j+1, s3);
        }

        return dp[i][j] = resS1 || resS2;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()){
            return false;
        }

        dp = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        return helpFunc(s1, s2, 0, 0, s3);
    }
};

int main(){
    Solution test;

    cout << test.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << test.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    cout << test.isInterleave("", "", "") << endl;
}