#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> tower_lvl = {(double)poured};

        for (int i = 0; i < query_row; ++i){
            vector<double> next_lvl(tower_lvl.size() + 1, 0);
            for (int j = 0; j < tower_lvl.size(); ++j){
                if (i == query_row && query_glass == j)
                    return min(1.0, tower_lvl[query_glass]);
                
                double flow = (tower_lvl[j] - 1) / 2.0;
                if (flow > 0){
                    next_lvl[j] += flow;
                    next_lvl[j + 1] += flow;
                }
            }
            tower_lvl = next_lvl;
        }

        return min(1.0, tower_lvl[query_glass]);
    }
};

int main(){
    Solution test;

    cout << test.champagneTower(1, 1, 1) << endl;
    cout << test.champagneTower(2, 1, 1) << endl;
    cout << test.champagneTower(100000009, 33, 17) << endl;
}