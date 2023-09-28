#include "../printSmth.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // O(n) time and O(n) space
    vector<int> sortArrayByParity_new_vec(vector<int>& nums) {
        vector<int> temp(nums.size());

        int i = 0;
        for (auto el: nums){
            if (el % 2 == 0)
                temp[i++] = el;
        }

        for (auto el: nums){
            if (el % 2 != 0)
                temp[i++] = el;
        }

        return temp;
    }

    // O(n) time and O(1) space
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] % 2 == 0)
                swap(nums[i], nums[j++]);
        }
        return nums;
    }
};

int main(){
    vector<int> test_case_1 = {3, 1, 2, 4};

    Solution test;

    printVec(test.sortArrayByParity(test_case_1));
    printVec(test.sortArrayByParity_new_vec(test_case_1));
}