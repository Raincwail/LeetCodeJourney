#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    double myPow_basic(double x, int n) {
        if (x == 1 || n == 0) {
            return 1;
        }

        double x_true = n < 0 ? 1/x : x;
        double res = x_true;

        cout << std::abs((long long)n) << endl;

        for (long long i = 1; i < abs((long long)n); ++i){
            res *= x_true;
        }

        return res;
    }

    double myPow(double x, long long n){
        if (n < 0){
            return myPow(1/x, -n);
        }

        if (n == 0) {
            return 1;
        }

        if (n % 2 != 0){
            return x * myPow(x * x, (n - 1)/2);
        }

        if (n % 2 == 0) {
            return myPow(x * x, n/2);
        }

        return -1;
    }

};

int main(){
    Solution test;

    cout << test.myPow(2.10000, -2147483648) << endl;
}