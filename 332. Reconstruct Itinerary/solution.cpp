#include "../printSmth.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

class Solution {
private:
    map<string, multiset<string>> graph;
    vector<string> ans;

    void helpFunc(string node){
        while (graph[node].size()){
            string cur = *graph[node].begin();
            graph[node].erase(graph[node].begin());
            helpFunc(cur);            
        }
        ans.push_back(node);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto ticket: tickets){
            graph[ticket[0]].insert(ticket[1]);
        }
        helpFunc("JFK");
        return vector<string>(ans.rbegin(), ans.rend());
    }
};
int main(){
    vector<vector<string>> test_case_1 = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};

    Solution test;

    auto res = test.findItinerary(test_case_1);
    printVec(res);
}