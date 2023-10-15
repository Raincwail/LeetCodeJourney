#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "../printSmth.h"

using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> difference;
        difference[0] = 0;
        
        for (vector<int>& flower : flowers) {
            difference[flower[0]]++;
            difference[flower[1] + 1]--;
        }
        
        vector<int> positions;
        vector<int> prefix;
        int curr = 0;
        for (auto& pair : difference) {
            positions.push_back(pair.first);
            curr += pair.second;
            prefix.push_back(curr);
        }
        
        vector<int> ans;
        for (int person : people) {
            int i = upper_bound(positions.begin(), positions.end(), person) - positions.begin() - 1;
            ans.push_back(prefix[i]);
        }
        
        return ans;
    }
};

int main(){
    vector<vector<int>> test_case_1_1 = {{1, 6}, {3, 7}, {9, 12}, {4, 13}};
    vector<int> test_case_1_2 = {2, 3, 7, 1};

    Solution test;

    auto res = test.fullBloomFlowers(test_case_1_1, test_case_1_2);
    printVec(res);
}