#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() < 2)
            return true;

        int dir;
        if (nums[0] == nums[nums.size() - 1])
            dir = 0;
        
        if (nums[0] > nums[nums.size() - 1])
            dir = 1;

        if (nums[0] < nums[nums.size() - 1])
            dir = -1;

        for (int i = 1; i < nums.size(); ++i){
            switch (dir){
                case 0:
                    if (nums[i] != nums[i - 1])
                        return false;
                    break;
                case 1:
                    if (nums[i] > nums[i - 1])
                        return false;
                    break;
                case -1:
                    if (nums[i] < nums[i - 1])
                        return false;
            }
        }

        return true;
    }
};
int main(){
    vector<int> test_case_1 = {1, 2, 2, 3};
    vector<int> test_case_2 = {6,5,4,4};
    vector<int> test_case_3 = {1,3,2};

    Solution test;

    cout << test.isMonotonic(test_case_1) << endl;
    cout << test.isMonotonic(test_case_2) << endl;
    cout << test.isMonotonic(test_case_3) << endl;
}