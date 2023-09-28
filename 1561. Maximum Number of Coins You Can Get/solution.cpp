#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int s = piles.size();
        sort(piles.begin(), piles.end());

        int ans = 0;
        for (int i = (s / 3); i < s; i += 2)
            ans += piles[i];

        return ans;
    }
};

int main(){
    vector<int> test_case_1 = {2, 4, 1, 2, 7, 8};
    vector<int> test_case_2 = {2, 4, 5};
    vector<int> test_case_3 = {9,8,7,6,5,1,2,3,4};

    Solution test;

    cout << test.maxCoins(test_case_1) << endl;
    cout << test.maxCoins(test_case_2) << endl;
    cout << test.maxCoins(test_case_3) << endl;
}