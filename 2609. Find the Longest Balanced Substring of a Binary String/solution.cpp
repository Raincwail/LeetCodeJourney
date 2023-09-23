#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int prev_sol = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '0'){
                prev_sol = 0;
            } else {
                if ((i - 1 >= 0) && (i - 2 * prev_sol - 1 >= 0) && (s[i - 2 * prev_sol - 1] == '0')){
                    prev_sol += 1;
                } else {
                    prev_sol = 0;
                }
            }
            
            ans = max(ans, prev_sol);
        }

        return 2 * ans;
    }
};

int main(){
    string test_case_1 = "01000111";
    string test_case_2 = "00111";
    string test_case_3 = "111";

    Solution test;

    cout << test.findTheLongestBalancedSubstring(test_case_1) << endl;
    cout << test.findTheLongestBalancedSubstring(test_case_2) << endl;
    cout << test.findTheLongestBalancedSubstring(test_case_3) << endl;
}
