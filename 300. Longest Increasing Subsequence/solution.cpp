#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> solution;

        for (auto num : nums){
            auto it = lower_bound(solution.begin(), solution.end(), num); // Get the position of the element next to i > num
            if (it == solution.end()){                                    // If there is no such element,
                solution.push_back(num);                                  // i.e. this element is greater than all elements in solution
                                                                          // Just push it back
            } else {                                                      // In the other case
                *it = num;                                                // Change it, so we will be open for more opportunities
            }
        }

        return solution.size();
    }
};

int main(){
    vector<int> test_case_1 = {10,9,2,5,3,7,101,18};
    vector<int> test_case_2 = {0,1,0,3,2,3};
    vector<int> test_case_3 = {7,7,7,7,7,7,7};

    Solution test;

    cout << test.lengthOfLIS(test_case_1) << endl;
    cout << test.lengthOfLIS(test_case_2) << endl;
    cout << test.lengthOfLIS(test_case_3) << endl;
}