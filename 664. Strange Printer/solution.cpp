#include <vector>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        int str_size = s.size();
        vector<vector<int>> dp(str_size, vector<int>(str_size, 0));

        for (int i = str_size - 1; i >= 0; --i){
            dp[i][i] = 1;   // Fill the base case with 1s, since we can print a single letter with 1 move
            for (int j = i + 1; j < str_size; ++j){
                dp[i][j] = dp[i][j-1] + 1; // Usually we want to add a single letter to an existing result,
                                          // i.e. we have 'ab', so to get 'abc' we have to make 1 move and add 'c'
                
                for (int k = i; k < j; ++k){ // This is the strange printer optimization
                                             // If we have overlapping characters, we can optimize the printing
                                             // i.e. in case of 'aba', we overlap on 0 - a and 2 - a
                                             // so we can print 'aaa' first then rewrite 1 - a to 1 - b and get 'aba'
                                             // As a result, printing 'aba' in 2 turns instead of 3
                    if (s[k] == s[j]){
                        dp[i][j] = min(                                 // We take the min between
                                       dp[i][j],                        // The best previously known solution
                                       dp[i][k] +                       // And the sum of the solution with full
                                                                        // single letter printing, i.e. 'aaa'
                                       (k+1<=j-1 ? dp[k+1][j-1] : 0)    // And the number of changes, i.e. 1 move of changing a to b
                                                                        // If there is even anything to change
                                      );
                    }
                }
            }
        }

        for (auto vec: dp){
            for (auto el: vec){
                cout << el << ' ';
            }
            cout << endl;
        }

        return dp[0][str_size-1];
    }
};

int main(){
    string test_case_1 = "aaabbb";
    string test_case_2 = "abc";
    string test_case_3 = "abcabc";

    Solution test;

    std::cout << test.strangePrinter(test_case_1) << endl;
    std::cout << test.strangePrinter(test_case_2) << endl;
    std::cout << test.strangePrinter(test_case_3) << endl;
}