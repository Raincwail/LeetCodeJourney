#include <iostream>

using namespace std;

class Solution {
const int MOD = 1e9 + 7;
public:
    int countOrders(int n) {
        long long count = 1;
        for (int i = 2; i <= n; ++i) {
            count = (count * (2 * i - 1) * i) % MOD;
        }
        return (int)count;
    }
};

int main(){
    Solution test;

    cout << test.countOrders(1) << endl;
    cout << test.countOrders(2) << endl;
}