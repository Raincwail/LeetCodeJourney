#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int last = *nums.rbegin();
        int min_el = last;

        long long ans = 0;
        for (auto i = nums.rbegin() + 1; i < nums.rend(); ++i){
            if (*i > last){
                long long blockNum = (*i + last - 1) / last;
                ans += blockNum - 1;
                last = *i / blockNum;
            } else {
                last = *i;
            }
        }

        return ans;
    }
};

int main(){
    vector<int> test_case_1 = {3,9,3};
    vector<int> test_case_2 = {1,2,3,4,5};

    Solution test;

    cout << test.minimumReplacement(test_case_1) << endl;
    cout << test.minimumReplacement(test_case_2) << endl;
}