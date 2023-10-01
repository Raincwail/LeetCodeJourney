#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // This is the first solution that comes to mind
    // A simple O(N2) going through all options
    // Not that interesting
    bool find132pattern_N2(vector<int>& nums) {
        bool searchForLess = false;        
        
        for (int i = nums.size() - 1; i > -1; --i){
            for (int j = i - 1; j > -1; --j){
                if (!searchForLess && nums[j] > nums[i]){
                    searchForLess = true;
                    continue;
                }
                
                if (searchForLess && nums[j] < nums[i])
                    return true;
            }
            searchForLess = false;
        }

        return false; 
    }

    // A linear solution
    // The idea is to remember the k elements value (thrd)
    // While saving up j values (consequently possible future k values)
    // Once we find i (nums[i] < thrd) we can say for sure that 132 is there

    // Example: [3 5 0 3 4]
    // 1. Ind: 4  Thrd: int_min  St: []
    // 2. Ind: 3  Thrd: int_min  St: [4]
    // 3. Ind: 2  Thrd: int_min  St: [4, 3]
    // 4. Ind: 1  Thrd: int_min  St: [4, 3, 0] <- Here we start poppin coz val = 5 
    // 5. Ind: 0  Thrd: 4        St: [5] <- And here we return true coz val = 3 < thrd = 4
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int thrd = INT_MIN;

        for (int i = nums.size() - 1; i > -1; --i){
            if (nums[i] < thrd)
                return true;

            while (!st.empty() && nums[i] > st.top()){
                thrd = st.top(); st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};

int main(){
    vector<int> test_case_1 = {1, 2, 3, 4};
    vector<int> test_case_2 = {3,1,4,2};
    vector<int> test_case_3 = {-1,3,2,0};

    Solution test;

    cout << test.find132pattern(test_case_1) << endl;
    cout << test.find132pattern(test_case_2) << endl;
    cout << test.find132pattern(test_case_3) << endl;
}