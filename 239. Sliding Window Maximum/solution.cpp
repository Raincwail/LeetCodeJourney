#include "../printSmth.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

class Solution {
private:
    void updateQ(deque<int>& q, int targ){
        while (!q.empty()){
            if (q.back() >= targ){
                break;
            }
            q.pop_back();
        }
        q.push_back(targ);
    }

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        if (nums.size() == k){
            return {*max_element(nums.begin(), nums.end())};
        }

        if (k == 1){
            return nums;
        }

        deque<int> q;
        vector<int> ans(nums.size() - k + 1);

        for (auto el = nums.begin(); el < nums.begin() + k; ++el){
            updateQ(q, *el);
        }

        int i = 0;

        for (auto el = nums.begin() + k; el < nums.end() ; ++el){
            ans[i] = q.front();

            updateQ(q, *el);

            if (nums[i] == q.front()){
                q.pop_front();
            }

            i++;
        }

        ans[i] = q.front();

        return ans;
    }
};

int main(){
    vector<int> test_case_1 = {1,3,-1,-3,5,3,6,7};
    vector<int> test_case_2 = {1};

    Solution test;

    printVec(test.maxSlidingWindow(test_case_1, 2));
    printVec(test.maxSlidingWindow(test_case_2, 1));
}