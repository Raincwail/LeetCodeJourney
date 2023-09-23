#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> x, y;
        vector<vector<int>> transpose;
        int dif = 0;

        for (auto i: grid) {

            x.push_back(*(max_element(i.begin(), i.end())));

        }

        for (int i = 0; i < grid.size(); ++i) {
            vector<int> temp;
            for (int j = 0; j < grid[i].size(); ++j) {
                temp.push_back(grid[j][i]);
            }
            transpose.push_back(temp);
        }

        for (auto i: transpose) {

            y.push_back(*(max_element(i.begin(), i.end())));

        }

        for (int i = 0; i != grid.size(); ++i){
            for (int j = 0; j != grid[i].size(); ++j){
                dif += abs(grid[i][j] - min(x[i], y[j]));
            }
        }

        return dif;
    };
};

int main(){
    vector<vector<int>> test_case_1 = {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};

    Solution test;

    cout << test.maxIncreaseKeepingSkyline(test_case_1) << endl;
}