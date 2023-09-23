#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool isEnough(vector<int>& nums, int p, int thresh){
        int val = 0;
        for (int i = 0; i < nums.size() - 1; ++i){
            if (val >= p)
                return val >= p;
            
            if (nums[i + 1] - nums[i] <= thresh){
                val++;
                i++;
                continue;
            }
        }

        return val >= p;
    }

public:
    int minimizeMax(vector<int>& nums, int p) {

        sort(nums.begin(), nums.end());

        int st = 0, en = nums[nums.size() - 1] - nums[0];

        while (st < en){
            int mid = st + (en - st) / 2;

            if (isEnough(nums, p, mid)){
                en = mid;
            } else {
                st = mid + 1;
            }

        }

        return st;
    }
};

int main(){
    vector<int> test_case_1 = {10,1,2,7,1,3};
    vector<int> test_case_2 = {4,2,1,2};

    Solution test;

    cout << test.minimizeMax(test_case_1, 2) << endl;
    cout << test.minimizeMax(test_case_2, 1) << endl;
}