#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int countVowelPermutation(int n) {
        vector<long> cur (5, 0);
        vector<long> prev(5, 1);

        for (int i = 0; i < n - 1; ++i){
            cur[0] = (prev[1] + prev[2] + prev[4]) % MOD;
            cur[1] = (prev[0] + prev[2]) % MOD;
            cur[2] = (prev[1] + prev[3]) % MOD;
            cur[3] = prev[2] % MOD;
            cur[4] = (prev[2] + prev[3]) % MOD;
        
            prev = cur;
        }

        return (prev[0] + prev[1] + prev[2] + prev[3] + prev[4]) % MOD;
    }
};

int main(){
    Solution test;

    cout << test.countVowelPermutation(3) << endl;
}