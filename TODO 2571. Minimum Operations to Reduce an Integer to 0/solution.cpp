#include <iostream>
#include <bitset>

using namespace std;
using ll = long long;

class Solution {
public:

    int minOperations(int n) {
        ll m = n;
        bitset<32> a(n);
        int res = 0;

        while (a.count() != 1 && ()){
            cout << m << endl;
            m += (m & -m);
            a = bitset<32>(m);
            res++;
        }

        return res;
    }

};

int main(){
    Solution test;

    cout << test.minOperations(39) << endl;
    // cout << test.minOperations(54) << endl;
};