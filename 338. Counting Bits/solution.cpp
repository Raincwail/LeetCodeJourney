#include "../printSmth.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits_bad(int n) {
        vector<int> ans;

        for (int i = 0; i <= n; ++i){
            ans.push_back(__builtin_popcount(i));
        }

        return ans;
    }
};
int main(){
    Solution test;

    auto res = test.countBits_bad(5);
    printVec(res);
}