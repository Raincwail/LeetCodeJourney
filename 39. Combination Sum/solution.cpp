#include "../printSmth.h"
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <functional>

using namespace std;

class Solution {
public:
    void helpFunc(vector<int>& candidates, int target, int i, vector<int>& curVec, int curTarget, vector<vector<int>>& res){
        // printVec(curVec);
        
        if (curTarget == target){
            res.push_back(curVec);
            return;
        }

        if (curTarget > target){
            return;
        }

        curVec.push_back(candidates[i]);
        helpFunc(candidates, target, i, curVec, curTarget + candidates[i], res);
        curVec.pop_back();

        if (i + 1 < candidates.size()){
            // curVec.push_back(candidates[i + 1]);
            // helpFunc(candidates, target, i + 1, curVec, curTarget + candidates[i + 1], res);
            // curVec.pop_back();
            
            helpFunc(candidates, target, i + 1, curVec, curTarget, res);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;

        helpFunc(candidates, target, 0, temp, 0, res);

        return res;    
    }
};

int main(){
    vector<int> test_case_1 = {2,3,6,7};
    vector<int> test_case_2 = {2,3,5};
    vector<int> test_case_3 = {2};

    Solution test;
    vector<vector<int>> toPrint;

    toPrint = test.combinationSum(test_case_1, 7);
    print2DVec(toPrint);

    toPrint = test.combinationSum(test_case_2, 8);
    print2DVec(toPrint);

    toPrint = test.combinationSum(test_case_3, 1);
    print2DVec(toPrint);
}