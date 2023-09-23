#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    int size;
    vector<int> dp_double;
    vector<int> dp_triple;
    vector<int> nums;

    bool correctTriple(int i){
        return (i + 2 < size) && 
               ((nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2]) ||
               (nums[i] == nums[i + 1] - 1 && nums[i + 1] == nums[i + 2] - 1)); 
    }

    bool correctDouble(int i){
        return nums[i] == nums[i + 1];
    }

    bool validPartition(vector<int>& nums) {
        this->nums = nums;
        this->size = nums.size();
        dp_double = vector<int>(size, -1);
        dp_triple = vector<int>(size, -1);
        return dfs(0, 1) || dfs(0, 2);
    }

    bool dfs(int i, int j){
        if (j >= size){
            return false;
        }

        bool isDouble = j - i < 2;

        if (isDouble && dp_double[i] != -1){
            return dp_double[i];
        }

        if (!isDouble && dp_triple[i] != -1){
            return dp_triple[i];
        }

        if (j - i == 1 && !correctDouble(i)) {
            dp_double[i] = false;
            return false;
        }

        if (j - i == 2 && !correctTriple(i)) {
            dp_triple[i] = false;
            return false;
        }


        if (isDouble){
            dp_double[i] = true;
            dp_double[i] = dp_double[i] && (j == size - 1 ? true : (dfs(j + 1, j + 2) || dfs(j + 1, j + 3)));
        
            return dp_double[i];
        } else {
            dp_triple[i] = true;
            dp_triple[i] = dp_triple[i] && (j == size - 1 ? true : (dfs(j + 1, j + 2) || dfs(j + 1, j + 3)));
        
            return dp_triple[i];
        }
        
    }

};

int main(){
    vector<int> test_case_1 = {4,4,4,5,6};
    vector<int> test_case_2 = {1,1,1,2};

    Solution test;

    cout << test.validPartition(test_case_1) << endl;
    cout << test.validPartition(test_case_2) << endl;
}
