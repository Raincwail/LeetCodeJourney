#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n > 0) && !(n & (n - 1)) && (n % 3 == 1);
    }
};

int main(){
    Solution test;

    cout << test.isPowerOfFour(16) << endl;
    cout << test.isPowerOfFour(15) << endl;
}