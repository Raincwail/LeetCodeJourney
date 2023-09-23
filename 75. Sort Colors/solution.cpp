#include "../printSmth.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        ll low = 0;
        ll high = nums.size() - 1;
        
        for (int mid = 0; mid <= high; ++mid){
            if (nums[mid] == 0){
                nums[mid] = nums[low];
                nums[low] = 0;
                low++;
            } else if (nums[mid] == 2){
                nums[mid] = nums[high];
                nums[high] = 2;
                high--;
                mid--;
            }
        }
    }
};

int main(){
    vector<int> test_case_1 = {2,0,2,1,1,0};
    vector<int> test_case_2 = {0,0,1,1,2,2};

    Solution test;

    vector<int> res;
    test.sortColors(test_case_1);
    printVec(test_case_1);
    test.sortColors(test_case_2);
    printVec(test_case_2);
}