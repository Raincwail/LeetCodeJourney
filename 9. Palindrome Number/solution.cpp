#include "../printSmth.h"
#include <vector>
#include <iostream>

using namespace std;

using ll = long long;

class Solution {
public:
    bool isPalindrome_On(int x) {
        if (x < 0){
            return false;
        }

        vector<int> num;

        while (x != 0){
            num.push_back(x % 10);
            x = x / 10;
        }

        int s = num.size();
        for (int i = 0; i < s / 2; ++i){
            if (num[i] != num[s - i - 1]){
                return false;
            }
        }

        return true;
    }

    bool isPalindrome(int x){

        if (x < 0){
            return false;
        }

        ll toReverse = x;
        int reverse = toReverse % 10;

        while (toReverse /= 10){
            reverse = reverse * 10 + (toReverse % 10);
        }

        return reverse == x;
    }
};

int main(){
    Solution test;

    cout << test.isPalindrome(121) << endl;
    cout << test.isPalindrome(-121) << endl;
    cout << test.isPalindrome(10) << endl;
}