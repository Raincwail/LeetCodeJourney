#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char findTheDifference_map(string s, string t) {
        unordered_map<char, int> mp;
        for (const auto& el: s)
            mp[el]++;
         
        for (const auto& el: t)
            if (--mp[el] < 0)
                return el;
        
        return -1;
    }

    char findTheDifference(string s, string t) {
        char ans = 0;        
        for (int i = 0; i < s.size(); ++i)
            ans += t[i] - s[i];
        ans += t[t.size() - 1];
        return ans;
    }
};

int main(){
    Solution test;

    cout << test.findTheDifference("abcd", "abcde") << endl;
    cout << test.findTheDifference("", "y") << endl;
}