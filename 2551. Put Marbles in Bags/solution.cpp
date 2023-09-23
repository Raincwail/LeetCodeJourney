#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        if (weights.size() == k) {
            return 0;
        }
        
        vector<int> pair_sums(weights.size() - 1, 0);
        
        for (int i = 0; i < pair_sums.size(); ++i){
            pair_sums[i] = weights[i] + weights[i + 1];
        }
        
        sort(pair_sums.begin(), pair_sums.end());

        long long min_sum = weights[0] + weights[weights.size() - 1], max_sum = weights[0] + weights[weights.size() - 1];
        
        for (int i = 0; i < k - 1; ++i){
            min_sum += pair_sums[i];
            max_sum += pair_sums[pair_sums.size() - i - 1];
        }

        return max_sum - min_sum;
    }
};


int main(){
    vector<int> test_case_1 = {1,3,5,1};
    vector<int> test_case_2 = {1, 3};
    
    Solution test;

    cout << test.putMarbles(test_case_1, 2) << endl;
    cout << test.putMarbles(test_case_2, 2) << endl;
}