#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    int effort[102][102];
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};

    int dijkstraMatrix(vector<vector<int>>& heights){
        int r = heights.size(), c = heights[0].size();

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {0, 0}}); // top-left cell
        effort[0][0] = 0;     // effort in top-left cell

        while (!pq.empty()){
            auto cur_top = pq.top();
            auto cur_ef = cur_top.first;
            auto cur = cur_top.second;
            int x = cur.first, y = cur.second;
            cur_ef = -cur_ef;
            pq.pop();

            if (cur_ef > effort[x][y])
                continue;

            if (x == r - 1 && y == c - 1)
                return cur_ef;

            for (int i = 0; i < 4; ++i){
                int new_x = x + dx[i], new_y = y + dy[i];

                if (new_x < 0 || new_x >= r || new_y < 0 || new_y >= c)
                    continue;

                int new_ef = max(effort[x][y], abs(heights[x][y] - heights[new_x][new_y]));

                if (new_ef < effort[new_x][new_y]){
                    effort[new_x][new_y] = new_ef;
                    pq.push({-new_ef, {new_x, new_y}});
                }
            }
        }

        return effort[r - 1][c - 1];
    }

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        for (int i = 0; i < heights.size(); ++i){
            for (int j = 0; j < heights[0].size(); ++j){
                effort[i][j] = INT_MAX;
            }
        }

        return dijkstraMatrix(heights);
    }
};

int main(){
    vector<vector<int>> test_case_1 = {{1,2,2},{3,8,2},{5,3,5}};
    vector<vector<int>> test_case_2 = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};

    Solution test;

    cout << test.minimumEffortPath(test_case_1) << endl;
    cout << test.minimumEffortPath(test_case_2) << endl;
}