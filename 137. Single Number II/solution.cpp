#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> solution_map;
        int res;
        
        for (const auto num: nums){
            auto search_res = solution_map.find(num);
            if (search_res != solution_map.end()){
                solution_map[num] += 1;
            } else {
                solution_map.insert({num, 1});
            }
        }

        for (const auto elem: solution_map) {
            if (elem.second == 1){
                res = elem.first;
            }
        }

        return res;
    }

    int singleNumber2(vector<int>& nums){
        int res = -232;

        if (nums.size() < 4){
            return nums[0];
        }

        sort(nums.begin(), nums.end());

        for (auto i = 1; i < nums.size() - 1; i += 3){
            if (nums[i - 1] != nums[i]) {
                res = nums[i - 1];
                break;
            }

            if (nums[i + 1] != nums[i]) {
                res = nums[i + 1];
                break;
            }

            if (i == nums.size() - 3){
                
                if (res == -232) res = nums[nums.size() - 1];
                
                break;
            }
        }

        return res;
    }

}; 

int main(){

    vector<int> test_case_1 = {2, 2, 3, 2};
    vector<int> test_case_2 = {0,1,0,1,0,1,99};

    Solution test;

    std::cout << test.singleNumber2(test_case_1) << endl;
    std::cout << test.singleNumber2(test_case_2) << endl;

}