#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        ll f = 0;
        ll s = 0;
        ll sum = 0;
        ll ans = INT_MAX;

        while (s < nums.size()){
            if (sum >= target){
                ans = min(ans, s - f);
                sum -= nums[f];
                f++;
                continue;
            }

            s++;
            sum += nums[s];
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

int main(){
    vector<int> test_case_1 = {2,3,1,2,4,3};
    vector<int> test_case_2 = {1,4,4};
    vector<int> test_case_3 = {1,1,1,1,1,1,1,1};

    Solution test;

    cout << test.minSubArrayLen(7, test_case_1) << endl;
    cout << test.minSubArrayLen(4, test_case_2) << endl;
    cout << test.minSubArrayLen(11, test_case_3) << endl;
}