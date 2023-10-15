#include <iostream>
#include <vector>
#include "../printSmth.h"

using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> tmp(8);
        vector<vector<int>> finite_machine;
        
        while (n--){
            for (size_t i = 1; i < cells.size() - 1; ++i){
                tmp[i] = cells[i - 1] == cells[i + 1];
            }

            if (finite_machine.size() && finite_machine.front() == tmp)
                return finite_machine[n % finite_machine.size()];
        
            finite_machine.push_back(tmp);
            cells = tmp;
        }

        return cells;
    }
};

int main(){
    vector<int> test_case_1 = {0,1,0,1,1,0,0,1};

    Solution test;

    auto res = test.prisonAfterNDays(test_case_1, 7);
    printVec(res);
}