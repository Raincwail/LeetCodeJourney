#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        size_t s = dist.size();
        vector<double> appRate(s);

        for (int i = 0; i < s; ++i)
            appRate[i]  = ((double)dist[i] / speed[i]);
    
        sort(appRate.begin(), appRate.end());

        int ans = 0;
        for (int i = 0; i < s; ++i){
            if (i >= appRate[i])
                break;

            ans++;
        }

        return ans;
    }
};

int main(){
    vector<int> test_case_1_1 = {1,3,4};
    vector<int> test_case_1_2 = {1,1,1};

    Solution test;

    cout << test.eliminateMaximum(test_case_1_1, test_case_1_2) << endl;
}