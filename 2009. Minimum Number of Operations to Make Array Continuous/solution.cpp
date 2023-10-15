#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = INT_MAX, key = nums.size();

        set<int> unique(nums.begin(), nums.end());
        int dif = nums.size() - unique.size();

        vector<int> v;
        for (auto el: unique){
            v.push_back(el);
        }

        int r = 0;
        for (int l = 0; l < v.size(); ++l){
            while (r < v.size() && v[r] < v[l] + key)
                r++;

            ans = min(ans, l + key - r);
        }

        return ans;
    }
};

int main(){
    vector<int> test_case_1 = {4, 2, 5, 3};

    Solution test;

    cout << test.minOperations(test_case_1) << endl;
}