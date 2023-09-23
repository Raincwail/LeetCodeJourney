#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dispersion(n + 1);

        for (int i = 0; i < ranges.size(); ++i){
            int st = max(0, i - ranges[i]);
            int en = min(n, i + ranges[i]);

            dispersion[st] = max(dispersion[st], en); // If we can jump further, we jump further
        }

        int ans = 0, cur = 0, next = 0;

        for (int i = 0; i <= n; ++i){
            if (i > next){                            // Not reachable
                return -1;
            }
            
            if (i > cur){
                cur = next;
                ans++;
            }

            next = max(next, dispersion[i]);
        }

        return ans;

    }
};

int main(){
    vector<int> test_case_1 = {3,4,1,1,0,0};
    vector<int> test_case_2 = {0,0,0,0};

    Solution test;

    cout << test.minTaps(5, test_case_1) << endl;
    cout << test.minTaps(3, test_case_2) << endl;
}