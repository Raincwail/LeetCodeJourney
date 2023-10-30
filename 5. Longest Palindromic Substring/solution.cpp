#include <iostream>

using namespace std;

class Solution {
private:
    string ans = "";

    void moveOut(string& s, int l, int r){
        while(l >= 0 && r < s.size()){
            if (s[l] != s[r])
                break;
            l--; r++;
        }

        if (ans.size() < r - l)
            ans = s.substr(l + 1, r - l - 1);
    }

public:
    string longestPalindrome(string s) {
        for (int i = 0; i < s.size(); i++){
            moveOut(s, i, i);
            moveOut(s, i, i + 1);
        }
        return ans;
    }
};

int main(){
    Solution test;

    cout << test.longestPalindrome("babad") << endl;
}