#include <iostream>
#include <vector>

#include "../printSmth.h"

using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans(pref.size(), pref[0]);

        for (int i = 1; i < pref.size(); ++i)
            ans[i] = pref[i - 1] ^ pref[i];

        return ans;
    }
};

int main(){
    vector<int> test_case_1 = {5, 2, 0, 3, 1};

    Solution test;

    auto res = test.findArray(test_case_1);
    printVec(res);
}