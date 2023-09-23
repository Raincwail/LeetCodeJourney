#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        int j = 0;
        for (int i = 0; i < m && j < n; i++)
            if (s[j] == t[i])
                j++;

        return (j == n);
    }
};

int main(){
    Solution test;

    cout << test.isSubsequence("abc", "ahbgdc") << endl;
}