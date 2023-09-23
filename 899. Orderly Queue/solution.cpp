#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    int minElemInd(string s){
        int ans = INT_MAX;
        int ans_ind = 0;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] < ans){
                ans = s[i];
                ans_ind = i;
            }
        }
        return ans_ind;
    }

    void move(string& s, int i, int j){
        while (i > j){
            s[i] = s[i - 1];
            i--;
        }
    }

    string orderlyQueue(string s, int k) {
        int size = s.size();
        vector<int> ans(s.begin(), s.end());

        int iter = 0;
        while (k--){
            int ind = minElemInd(s.substr(iter, size)) + iter;
            char temp = s[ind];

            cout << temp << endl;

            if (s[iter] == temp){
                iter++;
                size--;
                continue;
            }

            move(s, ind, iter);

            s[iter] = temp;
            size--;
            iter++;
        }

        return s;
    }
};
int main(){
    Solution test;
    // cout << test.orderlyQueue("cba", 1) << endl;
    // cout << test.orderlyQueue("baaca", 3) << endl;
    cout << test.orderlyQueue("qewjqfvurv", 6) << endl;
}

