#include "../printSmth.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:

    vector<int> asteroidCollision_2(vector<int>& asteroids){

        stack<int> q;

        for (auto el: asteroids){
            if (el > 0) {
                q.push(el);
            } else {

                while (!q.empty() && q.top() > 0 && q.top() < -el) {
                    q.pop();
                }

                if (q.empty() || q.top() < 0) {
                    q.push(el);
                }

                if (!q.empty() && q.top() == -el){
                    q.pop();
                }
                
            }
        }

        int i = q.size() - 1;
        vector<int> res(q.size());
        while (!q.empty()){
            res[i--] = q.top();
            q.pop();
        }

        return res;
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> skipAst(asteroids.size(), 0);

        for (const auto & el: asteroids){
            cout << el << ' ';
        }
        cout << endl;

        int i = 0;
        while (i < asteroids.size()){
            if (i >= asteroids.size() - 1){
                break;
            }

            if (skipAst[i]){
                i++;
                continue;
            }

            int j = i + 1;
            while (skipAst[j]){
                j++;
                if (j > skipAst.size() - 1){
                    break;
                }
            }

            if (j > skipAst.size() - 1){
                    break;
            }

            if (asteroids[i] > 0 && asteroids[j] < 0){
                int diff = asteroids[i] + asteroids[j];
                if (diff > 0) {
                    skipAst[j] = 1;
                    continue;
                } else if (diff == 0){
                    skipAst[i] = 1;
                    skipAst[j] = 1;
                    i = 0;
                    continue;
                } else {
                    skipAst[i] = 1;
                    i = 0;
                    continue;
                }
            }

            i++;
        }

        vector<int> res;
        for (int k = 0; k < skipAst.size(); ++k){
            if (!skipAst[k]){
                res.push_back(asteroids[k]);
            }
        }

        return res;
    }
};
int main(){
    vector<int> test_case_1 = {5, 10, -5};
    vector<int> test_case_2 = {8, -8};
    vector<int> test_case_3 = {10, 2, -5};
    vector<int> test_case_4 = {-1, -2, 2, 1};
    vector<int> test_case_5 = {46, -36, 3, 39, 20, -33, 35, 4, -26, -37, 27, -50, -23, 48, 5, -1, 29, -34, 34, 11, 22, 8, 41, -20, -10, 17, 35, -14, -9, 3, 12, -13, -47, 23, -39, 25, -43, -2, 26, -26, -42, -5, -4, 34, 3, 25, 20, 27, -6};
    
    Solution test;

    vector<int> res;
    // res = test.asteroidCollision(test_case_1);
    // printVec(res);
    // res = test.asteroidCollision(test_case_2);
    // printVec(res);
    // res = test.asteroidCollision(test_case_3);
    // printVec(res);
    // res = test.asteroidCollision(test_case_4);
    // printVec(res);
    res = test.asteroidCollision_2(test_case_5);
    printVec(res);
}