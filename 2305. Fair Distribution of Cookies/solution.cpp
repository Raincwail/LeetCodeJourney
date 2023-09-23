#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    void help_func_2(int ind, const vector<int>& cookies, vector<int>& distribution, int& ans){
        if (ind == cookies.size()){
            int max_el = *max_element(distribution.begin(), distribution.end());
            ans = min(ans, max_el);
            return;
        }

        for (int d_ind = 0; d_ind < distribution.size(); d_ind++){
            distribution[d_ind] += cookies[ind];
            help_func(ind + 1, cookies, distribution, ans);
            distribution[d_ind] -= cookies[ind];
            if (distribution[d_ind] == 0) break;
        }
    }

    void help_func(int ind, const vector<int>& cookies, vector<int>& distribution, int& ans){
        if (ind == cookies.size()){
            int max_el = *max_element(distribution.begin(), distribution.end());
            ans = min(ans, max_el);
            return;
        }

        for (int d_ind = 0; d_ind < distribution.size(); d_ind++){
            distribution[d_ind] += cookies[ind];
            help_func(ind + 1, cookies, distribution, ans);
            distribution[d_ind] -= cookies[ind];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int ans = INT_MAX;
        vector<int> distribution(k, 0);
        help_func(0, cookies, distribution, ans);
        return ans;
    }
};

int main(){
    vector<int> test_case_1 = {8,15,10,20,8};
    vector<int> test_case_2 = {6,1,3,2,2,4,1,2};
    vector<int> test_case_3 = {76265,7826,16834,63341,68901,58882,50651,75609};

    Solution test;

    cout << test.distributeCookies(test_case_1, 2) << endl;
    cout << test.distributeCookies(test_case_2, 3) << endl;
    cout << test.distributeCookies(test_case_3, 8) << endl;
}