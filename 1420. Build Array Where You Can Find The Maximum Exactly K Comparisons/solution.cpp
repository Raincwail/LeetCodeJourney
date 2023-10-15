#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int n, m;
    int MODULO = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int helpFunc(int a, int b, int c){
        if (c < 0)
            return 0;

        if (a == n){
            if (c == 0)
                return 1;
            return 0;
        }

        if (dp[a][b][c] != -1)
            return dp[a][b][c];

        int ans = 0;
        int temp = helpFunc(a + 1, b, c);

        // cout << a + 1 << ' ' << b << ' ' << c << ' ' << temp << endl;

        for (int i = 1; i <= b; ++i){
            ans = (ans + temp) % MODULO;
        }

        for (int i = b + 1; i <= m; ++i){
            ans = (ans + helpFunc(a + 1, i, c - 1)) % MODULO;
            // cout << a + 1 << ' ' << i << ' ' << c << ' ' << ans << endl;
        }

        return dp[a][b][c] = ans;
    }

public:
    int numOfArrays(int n, int m, int k) {
        if (m < k)
            return 0;

        if (m == k)
            return 1;
        
        this->n = n;
        this->m = m;
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));

        return helpFunc(0, 0, k);
    }
};

int main(){
    Solution test;

    cout << test.numOfArrays(2, 3, 1) << endl;
}