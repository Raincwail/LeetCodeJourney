#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int nodeNum = graph.size();
        unordered_set<int> visited;
        queue<tuple<int, int, int>> q;

        for (int i = 0; i < nodeNum; ++i){
            q.push({1 << i, i, 0});
            visited.insert((1 << i) * 16 + i); // Hash the value to keep track of node traversal order
        }

        while (!q.empty()){
            tuple<int, int, int> cur = q.front();
            q.pop();

            auto mask = get<0>(cur);
            auto node = get<1>(cur);
            auto dist = get<2>(cur);

            if (mask == (1 << nodeNum) - 1)    // We visited every node, yuppie!!
                return dist;

            for (int nbor: graph[node]){       // We have to explore the neighbors :(
                int nbor_mask = mask | (1 << nbor); // Add the visited bit
                int hash_nbor = mask * 16 + nbor;

                if (visited.find(hash_nbor) == visited.end()){
                    visited.insert(hash_nbor);
                    q.push({nbor_mask, nbor, dist + 1});
                }

            }
        }

        return -1;
    }
};

int main(){
    vector<vector<int>> test_case_1 = {{1,2,3},{0},{0},{0}};
    vector<vector<int>> test_case_2 = {{1},{0,2,4},{1,3,4},{2},{1,2}};

    Solution test;

    cout << test.shortestPathLength(test_case_1) << endl;
    cout << test.shortestPathLength(test_case_2) << endl;
}