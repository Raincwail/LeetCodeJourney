#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lookUpTableLast(string needle){
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

        return ans[ans.size() - 1];
    }
    

    string shortestPalindrome(string s) {
        string rev = s;

        reverse(rev.begin(), rev.end());
        // cout << lookUpTableLast(s + ' ' + rev) <<  endl;

        return rev.substr(0, rev.size() - lookUpTableLast(s + ' ' + rev)) + s;
    }
};

int main(){
    Solution test;

    cout << test.shortestPalindrome("aacecaaa") << endl;
    cout << test.shortestPalindrome("abcd") << endl;
}