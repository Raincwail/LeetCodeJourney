#include "../printSmth.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;

        for (int i = 0; i != index.size(); ++i){
            res.insert(res.begin() + index[i], nums[i]);
        }

        return res;
    }
};
int main(){
    vector<int> nums_1 = {0,1,2,3,4};
    vector<int> ind_1 = {0,1,2,2,1};

    Solution test;

    auto res = test.createTargetArray(nums_1, ind_1);
    printVec(res);
}