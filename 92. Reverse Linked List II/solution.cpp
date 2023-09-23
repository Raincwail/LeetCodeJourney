#include "../ListNode.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i = 1;

        ListNode* iter = head;
        ListNode* last = new ListNode(-1, head);
        while (iter){

            if (i == left) {
                ListNode* st = last;
                ListNode* en = iter;
                while (i >= left && i < right && iter){
                    ListNode* temp = en->next;

                    en->next = temp->next;
                    temp->next = st->next;
                    st->next = temp;                    

                    i++;
                }

                break;
            }

            last = iter;
            iter = iter->next;
            i++;
        }

        return last->val == -1 ? last->next : head;
    }
};

int main(){
    vector<int> ts1 = {1, 2, 3, 4, 5};
    ListNode* test_case_1 = nullptr;

    Solution test;
    for (auto el = ts1.rbegin(); el != ts1.rend(); ++el){
        ListNode* tmp = new ListNode(*el, test_case_1);
        test_case_1 = tmp;
    }

    test_case_1->printList();
    test_case_1 = test.reverseBetween(test_case_1, 2, 4);
    test_case_1->printList();
}