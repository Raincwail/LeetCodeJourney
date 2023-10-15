#include <iostream>
#include <vector>
#include "../printSmth.h"

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> freq(A.size() + 1, 0);

        vector<int> ans(A.size());

        int count = 0;
        for (int i = 0; i < A.size(); ++i){
            if (++freq[A[i] - 1] == 2) count++;
            if (++freq[B[i] - 1] == 2) count++;
            ans[i] = count;
        }

        return ans;
    }
};

int main(){
    vector<int> test_case_1 = {1, 3, 2, 4};

    Solution test;

    auto res = test.findThePrefixCommonArray(test_case_1, test_case_1);
    printVec(res);
}