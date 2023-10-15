#include <iostream>
#include "../printSmth.h"

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int bord = nums.size() / 3;
        int f_me, s_me;
        int f_cnt = 0, s_cnt = 0;

        for (const int el: nums){
            if (el == f_me){
                f_cnt++;
            } else if (el == s_me){
                s_cnt++;
            } else if (f_cnt == 0){
                f_me = el;
                f_cnt = 1;
            } else if (s_cnt == 0){
                s_me = el;
                s_cnt = 1;
            } else {
                f_cnt--; s_cnt--;
            }
        }

        f_cnt = 0, s_cnt = 0;
        for (const int el: nums){
            if (el == f_me)
                f_cnt++;
            
            if (el == s_me)
                s_cnt++;
        }

        vector<int> ans;
        if (f_cnt > bord)
            ans.push_back(f_me);
        
        if (s_cnt > bord)
            ans.push_back(s_me);

        return ans;
    }
};

int main(){
    vector<int> test_case_1 = {1, 2, 3};

    Solution test;

    auto res = test.majorityElement(test_case_1);
    printVec(res);
}