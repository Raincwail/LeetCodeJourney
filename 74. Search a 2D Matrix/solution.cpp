#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        long long m = matrix.size();
        long long n = matrix[0].size();

        long long st = 0;
        long long en = m * n - 1;

        auto row = 0;
        auto col = 0;
        long long mid = 0;

        while (st < en){
            mid = st + (en - st) / 2;

            row = mid / n;
            col = mid % n;

            if (matrix[row][col] < target){
                st = mid + 1;
            } else {
                en = mid;
            }
        }

        mid = st + (en - st) / 2;
        row = mid / n;
        col = mid % n;

        return matrix[row][col] == target;
    }
};

int main() {
    vector<vector<int>> test_case_1 = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    vector<vector<int>> test_case_2 = {{1,3}};

    Solution test;

    // cout << test.searchMatrix(test_case_1, 3) << endl;
    // cout << test.searchMatrix(test_case_1, 13) << endl;
    cout << test.searchMatrix(test_case_2, 3) << endl;

}