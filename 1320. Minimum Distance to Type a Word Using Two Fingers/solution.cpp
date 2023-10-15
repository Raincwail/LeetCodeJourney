#include <iostream>
#include <cstring>

using namespace std;

using ll = long long;

ll dist(char a, char b){
    int x_1 = (a - 'A') % 6, y_1 = (a - 'A') / 6;
    int x_2 = (b - 'A') % 6, y_2 = (b - 'A') / 6;
 
    return abs(x_1 - x_2) + abs(y_1 - y_2);
}

class Solution {
private:
    const char befA = 'A' - 1;
    string s;
    ll dp[27][27][300];

    ll helpFunc(char lstL, char lstR, int i){
        if (i == s.size()){
            return 0;
        }
        
        if (dp[lstL - befA][lstR - befA][i] != -1){
            return dp[lstL - befA][lstR - befA][i];
        }

        ll left  = (lstL == befA ? 0 : dist(lstL, s[i])) + helpFunc(s[i], lstR, i + 1);
        ll right = (lstR == befA ? 0 : dist(lstR, s[i])) + helpFunc(lstL, s[i], i + 1);     

        return dp[lstL - befA][lstR - befA][i] = min(left, right);
    }

public:
    int minimumDistance(string word) {
        s = word;
        memset(dp, -1, sizeof(dp));
        return helpFunc(befA, befA, 0);    
    }
};

int main(){
    Solution test;

    cout << test.minimumDistance("CAKE") << endl;
}