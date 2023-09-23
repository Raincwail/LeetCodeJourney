#include <iostream>
#include <vector>

using namespace std;
using ll = long long;


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 1){
            return nums[0] == target;
        }

        ll st = 0;
        ll en = nums.size() - 1;

        while (st < en){
            ll mid = st + (en - st) / 2;

            if (nums[mid] > nums[en]){
                st = mid + 1;
            } else {
                en = mid;
            }
        }

        ll piv = st;
        cout << piv << endl;
        st = 0; en = nums.size() - 1;

        while (st <= en){
            ll mid = st + (en - st) / 2;
            int mid_el = nums[(mid + piv) % nums.size()];

            if (target == mid_el){
                return true;
            }

            if (target > mid_el){
                st = mid + 1;
            } else {
                en = mid - 1;
            }
        }

        return false;
    }
};

int main(){
    vector<int> test_case_1 = {2,5,6,0,0,1,2};
    vector<int> test_case_2 = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};

    Solution test;

    vector<int> res;
    // cout << test.search(test_case_1, 0) << endl;
    // cout << test.search(test_case_1, 3) << endl;
    cout << test.search(test_case_2, 2) << endl;
}