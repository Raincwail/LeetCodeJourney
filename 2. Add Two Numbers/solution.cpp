#include "../ListNode.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* iter = dummy;

        ListNode *l1_iter = l1;
        ListNode *l2_iter = l2;

        int add = 0;
        while (l1_iter || l2_iter || add) {
            int sum_val = (l1_iter ? l1_iter->val : 0) +
                          (l2_iter ? l2_iter->val : 0) +
                          add;

            add = sum_val / 10;

            l1_iter = l1_iter ? l1_iter->next : nullptr;
            l2_iter = l2_iter ? l2_iter->next : nullptr;

            ListNode* temp = new ListNode(sum_val % 10);
            iter->next = temp;
            iter = iter->next;
        }
    
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};

int main(){
    vector<int> ts1 = {2, 4, 3};
    vector<int> ts2 = {5, 6, 4};
    ListNode* test_case_1 = nullptr;
    ListNode* test_case_2 = nullptr;
    ListNode* test_case_res = nullptr;

    Solution test;
    for (auto el = ts1.rbegin(); el != ts1.rend(); ++el){
        ListNode* tmp = new ListNode(*el, test_case_1);
        test_case_1 = tmp;
    }

    for (auto el = ts2.rbegin(); el != ts2.rend(); ++el){
        ListNode* tmp = new ListNode(*el, test_case_2);
        test_case_2 = tmp;
    }

    test_case_res = test.addTwoNumbers(test_case_1, test_case_2);
    test_case_res->printList();
}