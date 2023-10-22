#include <iostream>
#include <vector>
#include "../printSmth.h"

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res({1});
        long long prev = 1;

        for (int i = 1; i <= rowIndex; ++i){
            prev = prev * (rowIndex - i + 1) / i;
            res.push_back(prev);
        }

        return res;
    }
};

int main(){
    Solution test;

    auto res = test.getRow(3);
    printVec(res);
}