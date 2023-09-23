#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        
        if (batteries.size() < n) {
            return 0;
        }

        if (batteries.size() == n) {
            return *min_element(batteries.begin(), batteries.end());
        }

        long long all_sum = 0;
        for (int el: batteries) {
            all_sum += el;
        }

        long long st = 1;
        long long en = (long long) all_sum / n;

        // cout << "end " << en << endl;

        while (st <= en) {
            long long mid = st + (en - st) / 2;
            // cout << "m " << mid << endl;

            long long sum = 0;
            for (long long el: batteries){
                sum += min(mid, el);
            }

            if (sum >= mid * n) {
                st = mid + 1;
            } else {
                en = mid - 1;
            }
        }

        return st - 1;
    }
};

int main(){
    vector<int> test_case_1 = {3,3,3};
    vector<int> test_case_2 = {1,1,1,1};
    vector<int> test_case_3 = {10,10,3,5};
    
    Solution test;

    // cout << test.maxRunTime(2, test_case_1) << endl;
    // cout << test.maxRunTime(2, test_case_2) << endl;
    cout << test.maxRunTime(3, test_case_3) << endl;
}