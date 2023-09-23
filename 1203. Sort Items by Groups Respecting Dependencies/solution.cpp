#include "../printSmth.h"
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topologicalSorting(unordered_map<int, vector<int>>& map, vector<int>& indegree){
        stack<int> s;
        vector<int> ans;

        for (int i = 0; i < indegree.size(); ++i){
            if (indegree[i] == 0)
                s.push(i);
        }

        while (!s.empty()){
            int curr_i = s.top();
            s.pop();

            ans.push_back(curr_i);

            for (int el : map[curr_i]){
                indegree[el]--;
                if (indegree[el] == 0)
                    s.push(el);
            }
        }

        return ans.size() != indegree.size() ? vector<int>() : ans;
    }


    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int newGroupId = m;
        for (int i = 0; i < group.size(); ++i){
            if (group[i] == -1){
                group[i] = newGroupId++;
            }
        }

        unordered_map<int, vector<int>> item_graph;
        unordered_map<int, vector<int>> group_graph;

        vector<int> item_indegree(n, 0);
        vector<int> group_indegree(newGroupId, 0);

        for (int curr = 0; curr < beforeItems.size(); ++curr){
            for (int prev : beforeItems[curr]){
                item_graph[prev].push_back(curr);
                item_indegree[curr]++;

                if (group[prev] != group[curr]){
                    group_graph[group[prev]].push_back(group[curr]);
                    group_indegree[group[curr]]++;
                }
            }
        }

        vector<int> top_sort_item = topologicalSorting(item_graph, item_indegree);
        if (top_sort_item.size() == 0){
            return {};
        }

        vector<int> top_sort_group = topologicalSorting(group_graph, group_indegree);
        if (top_sort_group.size() == 0){
            return {};
        }

        unordered_map<int, vector<int>> ordered_groups;
        for (int el : top_sort_item){
            ordered_groups[group[el]].push_back(el);
        }

        vector<int> ans;
        for (int el : top_sort_group){
            ans.insert(ans.end(), ordered_groups[el].begin(), ordered_groups[el].end());
        }

        return ans;
    }
};

int main(){
    vector<int> group_1 = {-1,-1,1,0,0,1,0,-1};
    vector<vector<int>> before_1 = {{},{6},{5},{6},{3,6},{},{},{}};

    Solution test;

    auto res = test.sortItems(8, 2, group_1, before_1);
    printVec(res);
}