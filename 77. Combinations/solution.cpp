#include "../printSmth.h"
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <functional>

using namespace std;

class Solution {
public:
    void helpFunc(int curN, int n, int k, vector<int>& curVec, vector<vector<int>>& res){
        if (curVec.size() == k){
            res.push_back(curVec);
            return;
        }    
        
        if (curN <= n){
            curVec.push_back(curN);
            helpFunc(curN + 1, n, k, curVec, res);
            curVec.pop_back();
            helpFunc(curN + 1, n, k, curVec, res);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> res;

        helpFunc(1, n, k, temp, res);

        return res;
    }

    void helpFunc_def(int curN, int n, int k, vector<bool>& allowed, vector<int> curVec, int toAdd, vector<vector<int>>& res){
        curVec.push_back(toAdd);
        
        if (curVec.size() == k){
            res.push_back(curVec);
            return;
        }    
        
        for (int i = curN + 1; i <= n; ++i){
            if (allowed[i]){
                helpFunc_def(i, n, k, allowed, curVec, i, res);
            }
        }
    }

    vector<vector<int>> combine_def(int n, int k) {
        vector<bool> allowed(n, true);
        vector<vector<int>> res;

        for (int i = 1; i <= n; ++i){
            helpFunc_def(i, n, k, allowed, {}, i, res);
            allowed[i] = false;
        }

        return res;
    }
};

int main(){
    Solution test;
    vector<vector<int>> toPrint;

    toPrint = test.combine(4, 2);
    print2DVec(toPrint);

    toPrint = test.combine(1, 1);
    print2DVec(toPrint);
}