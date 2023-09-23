#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1){
            return nums[0] == target ? 0 : -1;
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
        st = 0; en = nums.size() - 1;

        while (st <= en){
            ll mid = st + (en - st) / 2;
            int mid_el = nums[(mid + piv) % nums.size()];

            if (target == mid_el){
                return (mid + piv) % nums.size();
            }

            if (target > mid_el){
                st = mid + 1;
            } else {
                en = mid - 1;
            }
        }

        return -1;
    }
};

int main(){
    vector<int> test_case_1 = {4,5,6,7,0,1,2};
    vector<int> test_case_2 = {1};
    vector<int> test_case_3 = {1, 3};

    Solution test;

    vector<int> res;
    cout << test.search(test_case_1, 0) << endl;
    cout << test.search(test_case_1, 3) << endl;
    cout << test.search(test_case_2, 0) << endl;
    cout << test.search(test_case_3, 3) << endl;
}