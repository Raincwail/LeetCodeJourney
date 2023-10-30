#include <iostream>
#include <math.h>

using namespace std;

using ll = long long;

class Solution {
public:
    int kthGrammar(int n, int k) {
        ll val = pow(2, n - 1);
        bool cur = 0;

        while (val != 1){
            // cout << val << ' ' << cur << endl;
            if (k > val / 2){
                cur = !cur;
                k -= val / 2;
            }

            val /= 2; 
        }

        return cur;
    }
};

int main(){
    Solution test;

    cout << test.kthGrammar(2, 2) << endl;
}