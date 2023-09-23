#include "../printSmth.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1){
            return {{1}};
        }

        if (numRows == 2){
            return {{1}, {1, 1}};
        }

        vector<vector<int>> ans = {{1}, {1, 1}};

        for (int i = 2; i < numRows; ++i){
            int last = ans.size() - 1;
            vector<int> temp(last + 2, 1);
            for (int j = 0; j < ans[last].size() - 1; ++j){
                temp[j + 1] = ans[last][j] + ans[last][j + 1];
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

int main(){
    Solution test;

    auto res = test.generate(5);
    print2DVec(res); 
}