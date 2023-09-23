#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <functional>

using namespace std;

class Solution {
public:
    double knightProbability_2(int n, int k, int row, int column) {
        vector<pair<int, int>> directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>> (n, vector<double>(n, -1)));

        function<double(int, int, int)> calculateDP = [&](int moves, int i, int j) -> double {
            // Base case
            if (moves == 0) {
                if (i == row && j == column) {
                    return 1;
                } else {
                    return 0;
                }
            }

            // Check if value has already been calculated
            if (dp[moves][i][j] != -1) {
                return dp[moves][i][j];
            }

            dp[moves][i][j] = 0;

            // Iterate over possible directions
            for (const auto& direction : directions) {
                int prevI = i - direction.first;
                int prevJ = j - direction.second;

                // Boundary check
                if (prevI >= 0 && prevI < n && prevJ >= 0 && prevJ < n) {
                    dp[moves][i][j] += calculateDP(moves - 1, prevI, prevJ) / 8.0;
                }
            }

            return dp[moves][i][j];
        };

        // Calculate the total probability by summing up the probabilities for all cells
        double totalProbability = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                totalProbability += calculateDP(k, i, j);
            }
        }

        return totalProbability;
    }
    
    // Possible solution, but TLE coz O(8^k) which is sad...
    double knightProbability(int n, int k, int row, int column) {

        if (k == 0) {
            return 1;
        }

        queue<pair<long long, long long>> q;
        q.push({row, column});

        vector<pair<int, int>> moves = {{-2, -1}, {-1, -2},
                                        {+1, -2}, {+2, -1},
                                        {+2, +1}, {+1, +2},
                                        {-1, +2}, {-2, +1}};

        long long allMoves = pow(8, k);

        while (k--){
            long long qSize = q.size();

            while (qSize--){
                pair<long long, long long> p = q.front();
                q.pop();

                for (auto move: moves){
                    auto newP_first = move.first + p.first;
                    auto newP_second = move.second + p.second;
                    if (newP_first < 0 || newP_first > n - 1 || newP_second < 0 || newP_second > n - 1){
                        continue;    
                    }

                    // cout << "m " << move.first << " " << move.second << endl;
                    // cout << newP_first << " " << newP_second << endl;

                    q.push({newP_first, newP_second});
                }

            }

        }

        cout << "Vm " << q.size() << " Am " << allMoves << endl;

        return allMoves;
    }
};

int main(){
    Solution test;
    
    cout << test.knightProbability_2(3, 2, 0, 0) << endl;
    cout << test.knightProbability_2(1, 0, 0, 0) << endl;
}