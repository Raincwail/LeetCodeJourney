#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare = nums[0];
        int tort = nums[0];

        while (true) {
            tort = nums[tort];
            hare = nums[nums[hare]];

            if (tort == hare) {
                break;
            }
        }

        hare = nums[0];

        while (tort != hare) {
            tort = nums[tort];
            hare = nums[hare];
        }

        return tort;  
    }
};

int main(){
    vector<int> test_case_1 = {1, 3, 4, 2, 2};
    vector<int> test_case_2 = {3, 1, 3, 4, 2};

    Solution test;

    cout << test.findDuplicate(test_case_1) << endl;
    cout << test.findDuplicate(test_case_2) << endl;
}