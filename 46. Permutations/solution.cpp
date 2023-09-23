#include "../printSmth.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void helpFunc(vector<int>& nums, vector<int>& isUsed, vector<int>& curVec, vector<vector<int>>& res){
        int n_size = nums.size(); 

        if (curVec.size() == n_size){
            res.push_back(curVec);
            return;
        }

        for (long long i = 0; i < n_size; ++i){
            if (!isUsed[i]){
                curVec.push_back(nums[i]);
                isUsed[i] = true;
                helpFunc(nums, isUsed, curVec, res);
                curVec.pop_back();
                isUsed[i] = false;
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<int> isUsed(nums.size(), 0);
        vector<vector<int>> res;

        helpFunc(nums, isUsed, temp, res);

        return res;
    }
};

int main(){
    vector<int> test_case_1 = {1,2,3};
    vector<int> test_case_2 = {0,1};
    vector<int> test_case_3 = {1};
    vector<int> test_case_4 = {1, 1, 2};

    Solution test;
    vector<vector<int>> toPrint;

    toPrint = test.permute(test_case_1);
    print2DVec(toPrint);

    toPrint = test.permute(test_case_2);
    print2DVec(toPrint);

    toPrint = test.permute(test_case_3);
    print2DVec(toPrint);

    toPrint = test.permute(test_case_4);
    print2DVec(toPrint);
}