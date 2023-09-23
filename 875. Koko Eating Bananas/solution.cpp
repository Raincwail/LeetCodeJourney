#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1;
        int en = *max_element(piles.begin(), piles.end());

        while (st < en) {

            int mid = st + (en - st) / 2;   
            // cout << st << ' ' << en << ' ' << mid << endl;

            long long sum = 0;
            for (auto el: piles){
                sum += ceil((double)el / mid);
            } 
            // cout << sum << endl;
            if (sum > h) {
                st = mid + 1;
            } else {
                en = mid;
            }
        }

        return st;
    }
};

int main(){
    vector<int> test_case_1 = {3,6,7,11};
    vector<int> test_case_2 = {30,11,23,4,20};
    vector<int> test_case_3 = {30,11,23,4,20};
    
    Solution test;

    cout << test.minEatingSpeed(test_case_1, 8) << endl;
    cout << test.minEatingSpeed(test_case_2, 5) << endl;
    cout << test.minEatingSpeed(test_case_3, 6) << endl;
}