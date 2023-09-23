#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        ll overallSum = 0;
        for (const auto el : nums)
            overallSum += el;

        ll toFind = overallSum - x;
        
        if (!toFind)
            return nums.size();

        if (toFind < 0)
            return -1;

        int l = 0, r = 0, maxLen = 0;
        ll curSum = nums[l];
        while (l <= r && r < nums.size()){
            if (curSum == toFind && r - l + 1 > maxLen){
                maxLen = r - l + 1;
            }

            if (curSum > toFind){
                curSum -= nums[l++];

                if (l != r + 1)
                    continue;
            }

            curSum += nums[++r];
        }

        return maxLen ? nums.size() - maxLen : -1;
    }
};

int main(){
    vector<int> test_case_1 = {1,1,4,2,3};
    vector<int> test_case_2 = {5,6,7,8,9};
    vector<int> test_case_3 = {3,2,20,1,1,3};

    Solution test;

    cout << test.minOperations(test_case_1, 5) << endl;
    cout << test.minOperations(test_case_2, 4) << endl;
    cout << test.minOperations(test_case_3, 10) << endl;
}