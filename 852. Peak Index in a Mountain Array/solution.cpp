#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        long long fst = 0;
        long long snd = arr.size() - 1;

        while (fst < snd){
            long long mid = fst + (snd - fst) / 2;

            // cout << mid << endl;

            if (arr[mid] > arr[mid + 1]){
                snd = mid;
            } else {
                fst = mid + 1;
            }
        }

        return fst;
    }
};

int main(){
    vector<int> test_case_1 = {0,1,0};
    vector<int> test_case_2 = {0,2,1,0};
    vector<int> test_case_3 = {0,10,5,2};
    vector<int> test_case_4 = {18,29,38,59,98,100,99,98,90};
    
    Solution test;

    cout << test.peakIndexInMountainArray(test_case_1) << endl;
    cout << test.peakIndexInMountainArray(test_case_2) << endl;
    cout << test.peakIndexInMountainArray(test_case_3) << endl;
    cout << test.peakIndexInMountainArray(test_case_4) << endl;

}