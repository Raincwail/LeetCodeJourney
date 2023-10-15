#include <iostream>
#include <vector>
#include <algorithm>
#include "../printSmth.h"

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1, k, toSwap;
        for (k = n - 1; k >= 0; --k){
            if (nums[k] < nums[k + 1])
                break;
        }

        if (k < 0)
            reverse(nums.begin(), nums.end());
        else {
            for (toSwap = n; toSwap > k; toSwap--){
                if (nums[toSwap] > nums[k])
                    break;
            }
            swap(nums[toSwap], nums[k]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};

int main(){
    vector<int> test_case_1 = {1, 2, 3};

    Solution test;

    test.nextPermutation(test_case_1);
    printVec(test_case_1);
}