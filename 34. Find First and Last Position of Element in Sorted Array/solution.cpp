#include "../printSmth.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        int st = 0, en = nums.size() - 1;
        vector<int> ans = {-1, -1};

        while (st <= en){
            int mid = st + (en - st) / 2;

            if (nums[mid] == t){
                ans[0] = mid;
                en = mid - 1;
                continue;
            }

            if (t > nums[mid])
                st = mid + 1;
            else
                en = mid - 1;
        }

        st = 0, en = nums.size() - 1;
        while (st <= en){
            int mid = st + (en - st) / 2;

            if (nums[mid] == t){
                ans[1] = mid;
                st = mid + 1;
                continue;
            }

            if (t > nums[mid])
                st = mid + 1;
            else
                en = mid - 1;
        }

        return ans;
    }
};

int main(){
    vector<int> test_case_1 = {5,7,7,8,8,10};
    vector<int> test_case_2 = {};
    vector<int> test_case_3 = {2, 2};

    Solution test;

    vector<int> res;
    res = test.searchRange(test_case_1, 8);
    printVec(res);
    res = test.searchRange(test_case_1, 6);
    printVec(res);
    res = test.searchRange(test_case_2, 0);
    printVec(res);
    res = test.searchRange(test_case_3, 2);
    printVec(res);
}