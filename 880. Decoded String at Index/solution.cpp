#include <iostream>

using namespace std;

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long len = 0;
        for (const int& el: s){
            if (isdigit(el))
                len *= el - '0';
            else
                len++;
        }

        for (auto i = s.rbegin(); i < s.rend(); ++i){
            if (isdigit(*i)){
                len /= *i - '0';
                k %= len;
            } else {
                if (k == 0 || k == len)
                    return string(1, *i);
                
                len--;
            }
        }

        return "";
    }
};

int main(){
    Solution test;

    cout << test.decodeAtIndex("leet2code3", 10) << endl;
}