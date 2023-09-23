#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;

        for (auto el : nums){
            maxHeap.push(-el);
            if (maxHeap.size() > k) {
                maxHeap.pop();
            } 
        }

        return -maxHeap.top();
    }
};

int main(){
    vector<int> test_case_1 = {3,2,1,5,6,4};
    vector<int> test_case_2 = {3,2,3,1,2,4,5,5,6};

    Solution test;

    cout << test.findKthLargest(test_case_1, 2) << endl;
    cout << test.findKthLargest(test_case_2, 4) << endl;
}
