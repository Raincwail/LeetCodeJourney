#include "../printSmth.h"
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:

    class disjointedSet {
        vector<int> parent;
        vector<int> rank;
    public:
        disjointedSet(int n){
            parent.resize(n);
            rank.resize(n);
            for (int i = 0; i < n; ++i){
                parent[i] = i;
                rank[i] = 1;
            }
        }

        int find(int a){
            return parent[a] == a ? a : parent[a] = find(parent[a]);
        }

        void unite(int a, int b){
            int aP = find(a), bP = find(b);

            if (aP != bP){
                if (rank[aP] < rank[bP])
                    swap(aP, bP);
                
                parent[bP] = aP;
                rank[aP] += rank[bP];
            }
        }
    
        int getRank(int a){
            return rank[find(a)];
        }

        void printRank(){
            for (auto el: rank){
                cout << el << ' ';
            }
            cout << endl;
        }

        void printParent(){
            for (auto el: parent){
                cout << el << ' ';
            }
            cout << endl;
        }
    };

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; ++i){
            edges[i].push_back(i);
        }
        
        disjointedSet ds(n);
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {return a[2] < b[2];});

        int ans = 0;
        for (int i = 0; i < m; ++i){
            auto edge = edges[i];

            if (ds.find(edge[0]) != ds.find(edge[1])){
                ans += edge[2];
                ds.unite(edge[0], edge[1]);
            }
        }

        vector<int> critEdge;
        vector<int> pseudoCritEdge;

        for (int i = 0; i < m; ++i){
            disjointedSet exclude(n);
            int excludeAns = 0;

            for (int j = 0; j < m; ++j){
                if (i == j)
                    continue;

                auto edge = edges[j];
                if (exclude.find(edge[0]) != exclude.find(edge[1])){
                    excludeAns += edge[2];
                    exclude.unite(edge[0], edge[1]);
                }
            }

            if (exclude.getRank(0) != n || excludeAns > ans){
                critEdge.push_back(edges[i][3]);
            } else {
                disjointedSet include(n);
                include.unite(edges[i][0], edges[i][1]);
                int includeAns = edges[i][2];

                for (int j = 0; j < m; ++j){
                    if (i == j)
                        continue;

                    auto edge = edges[j];

                    if (include.find(edge[0]) != include.find(edge[1])){
                        includeAns += edge[2];
                        include.unite(edge[0], edge[1]);
                    }
                }

                if (includeAns == ans){
                    pseudoCritEdge.push_back(edges[i][3]);
                }
            }

        }

        return {critEdge, pseudoCritEdge};
    }
};

int main(){
    vector<vector<int>> test_case_1 = {{0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6}};
    vector<vector<int>> test_case_2 = {{0,1,1},{1,2,1},{2,3,1},{0,3,1}};

    Solution test;
    vector<vector<int>> ans;

    ans = test.findCriticalAndPseudoCriticalEdges(5, test_case_1);
    print2DVec(ans);
    // ans = test.findCriticalAndPseudoCriticalEdges(4, test_case_2);
    // print2DVec(ans);
}