#include "../printSmth.h"
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void helpFunc(vector<int>& nums, unordered_map<int, long long>& isUsed, vector<int>& curVec, vector<vector<int>>& res){
        int n_size = nums.size(); 

        if (curVec.size() == n_size){
            res.push_back(curVec);
            return;
        }

        for (auto el: isUsed){
            if (isUsed[el.first] > 0){
                curVec.push_back(el.first);
                isUsed[el.first]--;
                helpFunc(nums, isUsed, curVec, res);
                curVec.pop_back();
                isUsed[el.first]++;
            }
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        unordered_map<int, long long> counter;
        vector<vector<int>> res;

        for (auto el: nums){
            counter[el]++;
        }

        helpFunc(nums, counter, temp, res);

        return res;
    }
};

int main(){
    vector<int> test_case_1 = {1,2,3};
    vector<int> test_case_2 = {1, 1, 2};

    Solution test;
    vector<vector<int>> toPrint;

    toPrint = test.permuteUnique(test_case_1);
    print2DVec(toPrint);

    toPrint = test.permuteUnique(test_case_2);
    print2DVec(toPrint);
}