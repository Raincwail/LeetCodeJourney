#include <iostream>

using namespace std;

class Solution {
private:
    int MOD = 1e9+7;
public:
    int countHomogenous(string s) {
        int ans = 1;
        int streak = 1;

        for (int i = 1; i < s.size(); ++i){
            if (s[i] != s[i - 1]){
                ans += 1;
                streak = 1;
                continue;
            }

            streak++;
            ans = (ans + streak) % MOD;
        }

        return ans;
    }
};

int main(){
    Solution test;

    cout << test.countHomogenous("abbcccaa") << endl;
}