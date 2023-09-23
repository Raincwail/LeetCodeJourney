#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        long long st = 1;
        long long en = 1e7;

        if (hour <= dist.size() - 1) {
            return -1;
        }

        while (st < en) {
            int n = (int) st + (en - st)/2;
            // cout << st << ' ' << en  << ' ' << n << endl;

            double time = 0;
            for (int i = 0; i < dist.size() - 1; ++i){
                if (time > hour) {
                    break;
                }
                time += ceil((double) dist[i] / n);
                // cout << ceil((double) dist[i] / n) << " ";
            }
            time += (double) dist[dist.size() - 1] / n;

            if (time > hour) {
                st = n + 1;
            } else {
                en = n;
            }

        }

        return st;
    }
};

int main(){
    vector<int> test_case_1 = {1,3,2};
    vector<int> test_case_2 = {1,3,2};
    vector<int> test_case_3 = {1,3,2};
    
    Solution test;

    cout << test.minSpeedOnTime(test_case_1, 6) << endl;
    cout << test.minSpeedOnTime(test_case_2, 2.7) << endl;
    cout << test.minSpeedOnTime(test_case_2, 1.9) << endl;
}