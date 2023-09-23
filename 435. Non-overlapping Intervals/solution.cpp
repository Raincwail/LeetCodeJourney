#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {return a[0] < b[0];});

        // for (auto in: intervals){
        //     cout << in[0] << " " << in[1] << "; ";
        // }
        // cout << endl;

        int pointer = 0;
        int deleted = 0;
        int moved = 0;

        // cout << "size: " <<intervals.size() << endl;

        while (true){

            // cout << "pointer " << pointer << " moved: " << moved << endl;

            if (pointer + moved + 1 >= intervals.size()){
                break;
            }

            int a = intervals[pointer][0], b = intervals[pointer][1];
            int c = intervals[pointer + moved + 1][0], d = intervals[pointer + moved + 1][1];
            
            if (b <= c) {
                pointer += moved + 1;
                moved = 0;
            } else {

                if (b < d) {
                    moved++;
                    deleted++;
                } else {
                    pointer += moved + 1;
                    moved = 0;
                    deleted++;
                }

            }
        }

        return deleted;

    }
};

int main(){
    vector<vector<int>> test_case_1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    vector<vector<int>> test_case_2 = {{1, 2}, {1, 2}, {1, 2}};
    vector<vector<int>> test_case_3 = {{1, 2}, {2, 3}};
    vector<vector<int>> test_case_4 = {{1, 2}, {1, 2}, {1, 2}, {1, 4}, {1, 4}, {1, 4}};
    vector<vector<int>> test_case_5 = {{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}};

    Solution test;

    cout << test.eraseOverlapIntervals(test_case_1) << endl;    
    cout << test.eraseOverlapIntervals(test_case_2) << endl;
    cout << test.eraseOverlapIntervals(test_case_3) << endl;
    cout << test.eraseOverlapIntervals(test_case_4) << endl;
    cout << test.eraseOverlapIntervals(test_case_5) << endl;
}
