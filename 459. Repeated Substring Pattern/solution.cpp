#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
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

public:
    bool repeatedSubstringPattern(string s) {
        // cout << s.substr(1,s.size()) <<endl;
        return strStr((s.substr(1,s.size()) + s).substr(0, 2 * (s.size() - 1)), s) != -1;
    }
};

int main(){
    Solution test;

    cout << test.repeatedSubstringPattern("abab") << endl;
}