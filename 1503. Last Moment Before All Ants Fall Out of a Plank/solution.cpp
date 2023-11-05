#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for (int num : left) {
            ans = max(ans, num);
        }
        
        for (int num : right) {
            ans = max(ans, n - num);
        }
        
        return ans;
    }
};

int main(){
    vector<int> test_case_1_l = {4, 3};
    vector<int> test_case_1_r = {0, 1};

    Solution test;

    cout << test.getLastMoment(4, test_case_1_l, test_case_1_r) << endl;
}