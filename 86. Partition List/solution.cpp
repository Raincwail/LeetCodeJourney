#include "../ListNode.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* bord = nullptr;
        ListNode* fbord = nullptr;
        ListNode* prev = nullptr;
        ListNode* next = head;

        while (next != nullptr){
            if (bord == nullptr && next->val >= x){
                bord = prev != nullptr ? prev : new ListNode(-101, next);
                fbord = bord;
            }

            if (bord != nullptr && next->val < x){
                auto temp = next;

                next = next->next;

                prev->next = temp->next;
                temp->next = bord->next;
                bord->next = temp;
                bord = temp;

                cout << (fbord == bord) << endl;

                continue;
            }

            prev = next;
            next = next->next;
        }

        if (fbord != nullptr && fbord->val == -101){
            cout << 'k' << endl;
            return fbord->next;
        }

        return head;
    }
};

int main() {
    vector<int> ts1 = {1, 2, 3};
    ListNode* test_case_1 = nullptr;

    Solution test;
    for (auto el = ts1.rbegin(); el != ts1.rend(); ++el){
        ListNode* tmp = new ListNode(*el, test_case_1);
        test_case_1 = tmp;
    }

    // cout << test_case_1 << endl;
    test_case_1->printList();
    test_case_1 = test.partition(test_case_1, 3);
    test_case_1->printList();

    // test.partition(nullptr, 0);

}