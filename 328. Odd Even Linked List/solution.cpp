#include "../ListNode.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odditer = new ListNode();
        ListNode* odd = odditer;
        ListNode* eveniter = new ListNode();
        ListNode* even = eveniter;

        ListNode* iter = head;
        int i = 0;

        while (iter != nullptr){
            ListNode* tmp = new ListNode(iter->val);

            if (i % 2 == 0){
                odditer->next = tmp;
                odditer = odditer->next;
            } else {
                eveniter->next = tmp;
                eveniter = eveniter->next;
            }

            iter = iter->next;
            i++;
        }

        if (odditer == nullptr){
            return even->next;
        }

        odditer->next = even->next;

        return odd->next;
    }
};

int main(){
    vector<int> ts1 = {1,2,3,4,5};
    ListNode* test_case_1 = nullptr;

    Solution test;
    for (auto el = ts1.rbegin(); el != ts1.rend(); ++el){
        ListNode* tmp = new ListNode(*el, test_case_1);
        test_case_1 = tmp;
    }

    // cout << test_case_1 << endl;
    test_case_1->printList();
    test_case_1 = test.oddEvenList(test_case_1);
    test_case_1->printList();
}