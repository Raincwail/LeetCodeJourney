#include "../printSmth.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto x: strs){
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }
        
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};

int main(){
    vector<string> test_case_1 = {"eat","tea","tan","ate","nat","bat"};
    vector<string> test_case_2 = {""};

    Solution test;
    vector<vector<string>> toPrint;

    toPrint = test.groupAnagrams(test_case_1);
    print2DVec(toPrint);

    toPrint = test.groupAnagrams(test_case_2);
    print2DVec(toPrint);
}