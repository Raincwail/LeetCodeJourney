#include "../printSmth.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < groupSizes.size(); ++i){
            groups[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> ans;
        for (auto el : groups){
            int i = el.first;
            for (auto i = el.second.begin(); i < el.second.end(); i += el.first){
                ans.push_back({i, i + el.first});
            }
        }

        return ans;
    }
};

int main(){
    vector<int> test_case_1 = {3,3,3,3,3,1,3};
    vector<int> test_case_2 = {2,1,3,3,3,2};

    Solution test;

    auto res = test.groupThePeople(test_case_1);
    printVec(res);

    res = test.groupThePeople(test_case_2);
    printVec(res);
}