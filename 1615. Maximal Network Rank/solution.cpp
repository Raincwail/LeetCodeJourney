#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = 0;
        unordered_map<int, vector<int>> links;

        for (auto el : roads){
            links[el[0]].push_back(el[1]);
            links[el[1]].push_back(el[0]);
        }

        for (int f = 0; f < n; ++f){
            for (int s = f + 1; s < n; ++s){
                bool sInF = (find(links[f].begin(), links[f].end(), s) != links[f].end());
                int rank = (sInF ? -1 : 0) + links[f].size() + links[s].size();
                ans = max(ans, rank);
            }
        }

        return ans;
    }
};

int main(){
    vector<vector<int>> test_case_1 = {{0,1},{0,3},{1,2},{1,3}};
    vector<vector<int>> test_case_2 = {{0,1},{0,3},{1,2},{1,3},{2,3},{2,4}};

    Solution test;

    cout << test.maximalNetworkRank(4, test_case_1) << endl;
    cout << test.maximalNetworkRank(5, test_case_2) << endl;
}