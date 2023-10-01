#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int l = -1, r = 0;

        string ans = "";
        for (r = 0; r < s.size(); ++r){
            if (s[r] == ' ' || r == s.size() - 1){
                int tmp = s[r] == ' ' ? r - 1 : r;
                
                while (tmp != l)
                    ans += s[tmp--];
                
                if (s[r] == ' ')
                    ans += ' ';

                l = r;
            }
        }

        return ans;
    }
};

int main(){
    Solution test;

    cout << test.reverseWords("God Ding") << endl;
}