#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int l = k, r = k;
        int ans = nums[k];
        int min_val = nums[k];

        while (l > 0 || r < nums.size() - 1){
            if (l == 0 || (r < nums.size() - 1 && nums[r + 1] > nums[l - 1]))
                r++;
            else
                l--;

            min_val = min(min_val, min(nums[r], nums[l]));
            ans = max(ans, min_val * (r - l + 1));
        }

        return ans;
    }
};

int main(){
    vector<int> test_case_1 = {1, 4, 3, 7, 4, 5};

    Solution test;

    cout << test.maximumScore(test_case_1, 3) << endl;
}