#include <iostream>
#include <vector>
#include <algorithm>

#include "../printSmth.h"

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int a, const int b){
            int f = __builtin_popcount(a), s = __builtin_popcount(b);
            return f == s ? a < b : f < s;
        });

        return arr;
    }
};

int main(){
    vector<int> test_case_1 = {1024, 512, 128, 64, 32, 16, 8, 4, 2, 1};

    Solution test;

    auto res = test.sortByBits(test_case_1);
    printVec(res);
}