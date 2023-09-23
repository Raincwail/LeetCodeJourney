#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int n;
    string s;
    unordered_map<int, int> dp;
    unordered_set<string> dictSet;

    int helpFunc(int st){
        if (st == n){
            return 0;
        }

        if (dp.find(st) != dp.end()){
            return dp[st];
        }

        int extraChar = helpFunc(st + 1) + 1;
        for (int i = st; i < n; ++i){
            auto curr = s.substr(st, i - st + 1);
            if (dictSet.find(curr) != dictSet.end()){
                extraChar = min(extraChar, helpFunc(i + 1));
            }
        }

        return dp[st] = extraChar;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        this->s = s;
        this->n = s.size();
        this->dictSet = unordered_set<string>(dictionary.begin(), dictionary.end());

        return helpFunc(0);
    }
};

int main(){
    vector<string> test_case_1 = {"leet","code","leetcode"};
    vector<string> test_case_2 = {"hello","world"};

    Solution test;

    cout << test.minExtraChar("leetscode", test_case_1) << endl;
    cout << test.minExtraChar("sayhelloworld", test_case_2) << endl;
}