#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, n = nums1.size() + nums2.size();
        vector<int> v(n);

        for (auto el : nums1)
            v[i++] = el;    
    
        for (auto el : nums2)
            v[i++] = el;

        sort(v.begin(), v.end());

        return n % 2 ? v[n / 2] : (v[n/2 - 1] + v[n/2]) / 2.0;
    }
};

int main(){
    vector<int> test_case_1 = {1, 3};
    vector<int> test_case_2 = {2};
    vector<int> test_case_3 = {3, 4};

    Solution test;

    cout << test.findMedianSortedArrays(test_case_1, test_case_2) << endl;
    cout << test.findMedianSortedArrays(test_case_1, test_case_3) << endl;
}