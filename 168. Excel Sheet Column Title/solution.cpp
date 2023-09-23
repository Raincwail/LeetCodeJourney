#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        while (columnNumber > 26){
            columnNumber--;            

            ans += 'A' + (columnNumber % 26);
            columnNumber /= 26;
        }

        ans += 'A' + columnNumber - 1;
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main(){
    Solution test;

    cout << test.convertToTitle(52) << endl;
    cout << test.convertToTitle(28) << endl;
    cout << test.convertToTitle(701) << endl;
}
