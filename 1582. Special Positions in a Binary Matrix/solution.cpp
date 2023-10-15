#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> rows(mat.size(), 0);
        vector<int> cols(mat[0].size(), 0);

        for (int i = 0; i < mat.size(); ++i){
            for (int j = 0; j < mat[0].size(); ++j){
                if (mat[i][j] == 1){
                    rows[i]++;
                    cols[j]++;
                }

            }
        }   

        int ans = 0;
        for (int i = 0; i < mat.size(); ++i){
            for (int j = 0; j < mat[0].size(); ++j){
                if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1){
                    ans++;
                }
            }
        }   

        return ans;
    }
};

int main(){
    vector<vector<int>> test_case_1 = {{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};

    Solution test;

    cout << test.numSpecial(test_case_1) << endl;
}