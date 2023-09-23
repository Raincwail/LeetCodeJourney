#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:

    int dp_vec_len;
    unordered_map<int, vector<int>> dp;

    int bs(vector<int>& vec, int s){
        int st = 0, en = vec.size() - 1;

        while (st <= en){
            int mid = st + (en - st) / 2;
            if (vec[mid] == s){
                return mid;
            } else if (vec[mid] > s){
                en = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return 0;
    }

    void addEntry(int k, int i, int val){
        if (dp.find(k) == dp.end()){
            dp[k] = vector<int>(dp_vec_len, -1);
        }
        dp[k][i] = val;
    }

    bool isThere(int k, int i){
        if (dp.find(k) == dp.end()){
            return false;
        }

        return dp[k][i] != -1;
    }

    bool helpFunc(vector<int>& stones, int k, int i){
        if (i == stones.size() - 1){
            return true;
        }

        if (i >= stones.size()){
            return false;
        }
        
        if (isThere(k, i)){
            return dp[k][i];
        }

        bool f = false, s = false, t = false;
        int bs_ind = bs(stones, stones[i] + k - 1);

        if (k - 1 && bs_ind){
            f = helpFunc(stones, k - 1 , bs_ind);
        }

        bs_ind = bs(stones, stones[i] + k);
        if (bs_ind){
            s = helpFunc(stones, k, bs_ind);
        }

        bs_ind = bs(stones, stones[i] + k + 1);
        if (bs_ind){
            t = helpFunc(stones, k + 1, bs_ind);
        }

        // cout << k << ' ' << i << ' ' << f << ' ' << s << ' ' << t << endl;

        addEntry(k, i, f || s || t);
        return dp[k][i];
    }

    bool canCross(vector<int>& stones) {
        if (stones[1] > stones[0] + 1){
            return false;
        }

        dp_vec_len = stones.size();
        return helpFunc(stones, 1, 1);
    }
};

int main(){
    vector<int> test_case_1 = {0,1,3,5,6,8,12,17};

    Solution test;

    cout << test.canCross(test_case_1) << endl;
}