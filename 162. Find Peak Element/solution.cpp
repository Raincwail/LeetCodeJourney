#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        long long fst = 0;
        long long snd = arr.size() - 1;

        while (fst < snd){
            long long mid = fst + (snd - fst) / 2;

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
    vector<int> test_case_1 = {1, 2, 3, 1};
    vector<int> test_case_2 = {1,2,1,3,5,6,4};

    Solution test;

    cout << test.findPeakElement(test_case_1) << endl;
    cout << test.findPeakElement(test_case_2) << endl;
}