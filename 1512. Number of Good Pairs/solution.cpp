#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        
        int ans = 0;
        for (const auto& el: nums){
            ans += m[el];
            m[el]++;
        }

        return ans;
    }
};

int main(){
    vector<int> test_case_1 = {1,2,3,1,1,3};

    Solution test;

    cout << test.numIdenticalPairs(test_case_1) << endl;
}