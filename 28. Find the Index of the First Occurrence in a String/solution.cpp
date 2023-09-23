#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> lookUpTable(string& needle){
        int i = 0, j = 1;
        int m = needle.size();
        vector<int> ans(m, 0);

        while (j < m){
            if (needle[i] == needle[j]){
                ans[j] = i + 1;
                i++;
            } else {
                i = i - 1 > 0 ? ans[i - 1] : 0;
                j = needle[i] == needle[j] ? j - 1 : j;
            }

            j++;
        }

        for (auto el : ans){
            cout << el << ' ';
        }

        return ans;
    }
    
    int strStr(string haystack, string needle) {
        vector<int> lookUp = lookUpTable(needle);
    
        int i = 0, j = 0;
        int n = haystack.size(), m = needle.size();

        while (i < n + 1){
            if (haystack[i] == needle[j]){
                j++;
            } else if (j != 0){
                j = lookUp[j - 1];
                i--;
            }

            i++;

            if (j == m){
                return i - m;
            }
        }

        return -1;
    }
};

int main(){
    Solution test;

    cout << test.strStr("sadbutsad", "sad") << endl;
    cout << test.strStr("leetcode", "leeto") << endl;
    cout << test.strStr("aabaaabaaac", "aabaaac") << endl;
    cout << test.strStr("ababcaababcaabc", "ababcaabc") << endl;
}