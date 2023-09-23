#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_map<std::string, bool> memo;
        std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());
        return dfs(s, wordSet, memo);
    }
    
private:
    bool dfs(const std::string& s, const std::unordered_set<std::string>& wordSet, std::unordered_map<std::string, bool>& memo) {
        if (memo.find(s) != memo.end()) return memo[s];
        if (wordSet.find(s) != wordSet.end()) return true;
        for (int i = 1; i < s.size(); i++) {
            std::string prefix = s.substr(0, i);
            if (wordSet.find(prefix) != wordSet.end() && dfs(s.substr(i), wordSet, memo)) {
                memo[s] = true;
                return true;
            }
        }
        memo[s] = false;
        return false;
    }
};

int main(){
    vector<string> test_case_1 = {"leet","code"};
    vector<string> test_case_2 = {"apple","pen"};
    vector<string> test_case_3 = {"cats","dog","sand","and","cat"};

    Solution test;
    vector<string> toPrint;

    cout << test.wordBreak("leetcode", test_case_1) << endl;
//     cout << test.wordBreak("applepenapple", test_case_2) << endl;
//     cout << test.wordBreak("catsandog", test_case_3) << endl;
}