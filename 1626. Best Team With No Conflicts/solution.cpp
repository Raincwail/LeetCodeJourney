#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int ans = -1;
        vector<pair<int, int>> players;

        for (int i = 0; i < scores.size(); ++i)
            players.push_back({ages[i], scores[i]});

        sort(players.begin(), players.end());

        vector<int> dp(scores.size());
        for (int i = 0; i < scores.size(); ++i){
            dp[i] = players[i].second;
            // cout << dp[i] << endl;
            for (int j = 0; j < i; ++j){
                if (players[j].second <= players[i].second)
                    dp[i] = max(dp[i], dp[j] + players[i].second);
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};

int main(){
    vector<int> test_case_1_1 = {1,3,5,10,15};
    vector<int> test_case_1_2 = {1,2,3,4,5};

    Solution test;

    cout << test.bestTeamScore(test_case_1_1, test_case_1_2) << endl;
}