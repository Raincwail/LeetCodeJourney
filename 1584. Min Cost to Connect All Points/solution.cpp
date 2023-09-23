#include <vector>
#include <queue>
#include <array>
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
                rank[i] = 0;
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

                if (rank[aP] == rank[bP])
                    rank[aP]++;
            }
        }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<array<int, 3>> dists;

        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                dists.push_back({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), i, j});
            }
        }

        disjointedSet ds(n);
        make_heap(dists.begin(), dists.end(), greater<array<int, 3>>());

        int ans = 0;
        while (!dists.empty()){
            pop_heap(dists.begin(), dists.end(), greater<array<int, 3>>());
            auto arr = dists.back();
            dists.pop_back();

            if (ds.find(arr[1]) != ds.find(arr[2])){
                ans += arr[0];
                ds.unite(arr[1], arr[2]);
            }
        }

        return ans;
    }
};

int main(){
    vector<vector<int>> test_case_1 = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    vector<vector<int>> test_case_2 = {{3,12},{-2,5},{-4,1}};
    vector<vector<int>> test_case_3 = {{-1000000,-1000000},{1000000,1000000}};

    Solution test;

    cout << test.minCostConnectPoints(test_case_1) << endl;
    cout << test.minCostConnectPoints(test_case_2) << endl;
    cout << test.minCostConnectPoints(test_case_3) << endl;
}