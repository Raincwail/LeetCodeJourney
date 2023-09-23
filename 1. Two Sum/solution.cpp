#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_pos;

        for (int i = 0; i < nums.size(); ++i){
            num_pos[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i){
            auto res = num_pos[target - nums[i]];
            if (res && i != res) {
                return {i, res};
            }
        }

        return {0, 0};
    };
};

int main(){
    vector<int> test_case_1 = {2, 7, 11, 15};
    vector<int> test_case_2 = {3, 2, 4};
    vector<int> test_case_3 = {3, 3};
    vector<int> test_case_4 = {1, 3, 4, 2};

    Solution test;

    auto test_res_1 = test.twoSum(test_case_1, 9);
    auto test_res_2 = test.twoSum(test_case_2, 6);
    auto test_res_3 = test.twoSum(test_case_3, 6);
    auto test_res_4 = test.twoSum(test_case_4, 6);

    std::cout << test_res_1[0] << " " << test_res_1[1] << endl;
    std::cout << test_res_2[0] << " " << test_res_2[1] << endl;
    std::cout << test_res_3[0] << " " << test_res_3[1] << endl;
    std::cout << test_res_4[0] << " " << test_res_4[1] << endl;
}