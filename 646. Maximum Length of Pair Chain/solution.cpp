#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        int ans = 0, last_b = -1001;
        for (auto el : pairs){
            if (last_b < el[0]){
                last_b = el[1];
                ans++;
            }
        }

        return ans;
    }
};

int main(){
    vector<vector<int>> test_case_1 = {{1,2},{2,3},{3,4}};

    Solution test;

    cout << test.findLongestChain(test_case_1) << endl;
}