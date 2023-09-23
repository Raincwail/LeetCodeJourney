#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        int ans = 0;
        unordered_map<string, int> dp;
        for (auto el: words){
            dp[el] = 1;
            for (int i = 0; i < el.size(); ++i){
                string prev = el.substr(0, i) + el.substr(i + 1);
                if (dp.find(prev) != dp.end()){
                    dp[el] = max(dp[el], dp[prev] + 1);
                }
            }
            ans = max(ans, dp[el]);
        }

        return ans;
    }
};

int main(){
    vector<string> test_case_1 = {"a","b","ba","bca","bda","bdca"};
    vector<string> test_case_2 = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
    vector<string> test_case_3 = {"abcd","dbqca"};

    Solution test;

    cout << test.longestStrChain(test_case_1) << endl;
    cout << test.longestStrChain(test_case_2) << endl;
    cout << test.longestStrChain(test_case_3) << endl;
}