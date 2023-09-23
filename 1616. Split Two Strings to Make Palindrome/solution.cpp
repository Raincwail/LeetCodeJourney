#include <vector>
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

class Solution {
public:
    bool checkPalindromeFormation_slow(string a, string b) {
        ll len = a.size();
        ll pos = 0;

        for (pos = 0; pos < len; pos++){
            string fst = a.substr(0, pos + 1) + b.substr(pos + 1, len);
            string snd = b.substr(0, pos + 1) + a.substr(pos + 1, len);
            if (equal(fst.begin(), fst.begin() + fst.size()/2, fst.rbegin()) ||
                equal(snd.begin(), snd.begin() + snd.size()/2, snd.rbegin())) {
                    return true;
                }
        }
    
        return false;
    }

    bool checkPa(string& a, ll i, ll j){
        while (i < j){
            if (a[i] != a[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool checkSuf(string& a, string& b){
        ll l = 0, r = a.size() - 1;
        while (l < r){
            if (a[l] != b[r]){
                return checkPa(a, l, r) ||
                       checkPa(b, l, r);
            }

            l++;
            r--;
        }

        return l>=r || false;
    }

    bool checkPalindromeFormation(string a, string b) {
        return checkSuf(a, b) || checkSuf(b, a);
    }
};

int main(){
    Solution test;

    cout << test.checkPalindromeFormation("x",  "y") << endl;
    cout << test.checkPalindromeFormation("xbdef", "xecab") << endl;
    cout << test.checkPalindromeFormation("ulacfd", "jizalu") << endl;
    cout << test.checkPalindromeFormation("abda", "acmc") << endl;
}