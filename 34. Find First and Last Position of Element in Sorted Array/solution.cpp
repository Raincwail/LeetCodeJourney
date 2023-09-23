#include "../printSmth.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if (nums.empty()){
            return {-1, -1};
        }
        
        int st = 0; int en = nums.size() - 1;

        int seed = -1;

        while (st <= en){
            int mid = st + (en - st)/2;
            if (target == nums[mid]){
                seed = mid;
                break;
            } else if (target > nums[mid]){
                st = mid + 1;
            } else {
                en = mid - 1;
            }
        }

        if (seed == -1){
            return {-1, -1};
        }

        st = seed; en = seed;
        while (st - 1 >= 0 && nums[st - 1] == target){
            st--;
        }

        while (en + 1 < nums.size() && nums[en + 1] == target){
            en++;
        }

        return {st, en};
    }

    vector<int> searchRange_2(vector<int>& nums, int t) {
        int start = 0;
        int end = nums.size()-1;
        int mid ;
        int res = -1;
        vector<int> ans;
        while(start <= end)
        {
            mid = start + (end-start)/2;
            if(nums[mid]==t)    
            {
                res = mid;
                end = mid-1;
            }
            else if(nums[mid]<t)
                start = mid+1;
            else
                end = mid-1;
        }
        ans.push_back(res);
        start = 0;
        end =nums.size()-1;
        res = -1;
        while(start<=end)
        {
            mid = start + (end-start)/2;
            if(nums[mid]==t)
            {
                res = mid;
                start = mid+1;
            }
            else if(nums[mid]<t)
                start = mid+1;
            else
                end = mid-1;
        }
        ans.push_back(res);
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