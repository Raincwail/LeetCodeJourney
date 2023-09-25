#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        for (const auto& el: s)
            mp[el]++;
         
        for (const auto& el: t)
            if (--mp[el] < 0)
                return el;
        
        return -1;
    }
};

int main(){
    Solution test;

    cout << test.findTheDifference("abcd", "abcde") << endl;
    cout << test.findTheDifference("", "y") << endl;
}