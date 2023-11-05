#include <iostream>
#include <vector>

#include "../printSmth.h"

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i = 1, j = 0;

        while (i <= n){
            while (i < target[j]){
                ans.push_back("Push");
                ans.push_back("Pop");
                i++;
            }

            ans.push_back("Push");
            i++;
            j++;

            if (j >= target.size())
                break;
        }

        return ans;
    }
};

int main(){
    vector<int> test_case_1 = {2, 3, 4, 5, 8, 9, 10};

    Solution test;

    auto res = test.buildArray(test_case_1, 10);
    printVec(res);
}