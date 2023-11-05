#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int max_el = *max_element(arr.begin(), arr.end());
        int cur = arr[0];
        int wins = 0;

        for (int i = 1; i < arr.size(); ++i){
            if (cur > arr[i])
                wins++;
            else {
                cur = arr[i];
                wins = 1;
            }

            if (wins == k || cur == max_el)
                return cur;
        }   

        return -1;
    }
};

int main(){
    vector<int> test_case_1 = {2,1,3,5,4,6,7};

    Solution test;

    cout << test.getWinner(test_case_1, 2) << endl;
}