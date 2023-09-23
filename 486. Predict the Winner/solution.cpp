#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

class Solution {
public:
    bool helpFunc(vector<int>& nums, ll sum_fst, ll sum_snd, bool isFst, ll st, ll en){
        
        // cout << isFst << ' ' << nums[st] << ' ' << nums[en] << endl;
        
        if (st == en) {
            // cout << sum_fst << ' ' << sum_snd << endl;
            isFst ? sum_fst += nums[st] : sum_snd += nums[en];
            return sum_fst >= sum_snd;
        }        
        
        if (isFst) {
            return helpFunc(nums, sum_fst + nums[st], sum_snd, false, st + 1, en) ||
                   helpFunc(nums, sum_fst + nums[en], sum_snd, false, st, en - 1);
        } else {
            return helpFunc(nums, sum_fst, sum_snd + nums[st], true, st + 1, en) &&
                   helpFunc(nums, sum_fst, sum_snd + nums[en], true, st, en - 1);
        }
    }

    bool PredictTheWinner(vector<int>& nums) {
        return helpFunc(nums, 0, 0, true, 0, nums.size() - 1);
    }
};


int main(){
    vector<int> test_case_1 = {1,5,2};
    vector<int> test_case_2 = {1,5,233,7};
    
    Solution test;

    cout << test.PredictTheWinner(test_case_1) << endl;
    cout << test.PredictTheWinner(test_case_2) << endl;
}