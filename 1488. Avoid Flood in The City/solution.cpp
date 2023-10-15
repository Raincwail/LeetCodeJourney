#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include "../printSmth.h"

using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> full;
        set<int> free;

        vector<int> ans(rains.size(), -1);
        for (int i = 0; i < rains.size(); ++i){
            if (rains[i] == 0){
                free.insert(i + 1);
                ans[i] = 1;
                continue;
            }

            if (full[rains[i]] != 0){
                if (free.empty()){
                    return {};
                }

                auto it = free.upper_bound(full[rains[i]]);
                // cout << *it << endl;
                if (it == free.end())
                    return {};

                ans[*it - 1] = rains[i];
                full[rains[i]] = 0;
                free.erase(it);
            }
            
            full[rains[i]] = i + 1;
            
        }

        return ans;
    }
};

int main(){
    vector<int> test_case_1 = {1, 2, 3, 4};

    Solution test;

    auto res = test.avoidFlood(test_case_1);
    printVec(res);
}