#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
private:
    vector<int> inDeg;
    vector<int> maxTime;
    vector<vector<int>> graph;

    void createGraph(int n, vector<vector<int>>& relations, vector<int>& time){
        inDeg = vector<int>(n, 0);
        maxTime = vector<int>(n, 0);
        graph = vector<vector<int>>(n);

        for (const auto& el: relations){
            inDeg[el[1] - 1]++;
            graph[el[0] - 1].push_back(el[1] - 1);
        }
    }

public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        createGraph(n, relations, time);

        int ans = 0;

        int temp;
        queue<int> q;
        
        for (int i = 0; i < n; ++i){
            if (inDeg[i] == 0){
                q.push(i);
                maxTime[i] = time[i];
            }
        }

        while(!q.empty()){
            int n = q.front(); q.pop();
            for (const auto& el: graph[n]){
                maxTime[el] = max(maxTime[el], maxTime[n] + time[el]);
                inDeg[el]--;
                
                if (inDeg[el] == 0)
                    q.push(el);
            }

        }

        return *max_element(maxTime.begin(), maxTime.end());
    }
};

int main(){
    vector<vector<int>> test_case_1_1 = {{1, 3}, {2, 3}};
    vector<int> test_case_1_2 = {3, 2, 5};

    Solution test;

    cout << test.minimumTime(3, test_case_1_1, test_case_1_2) << endl;
}