#include "../ListNode.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *hare = head;
        ListNode *tort = head;

        while(hare != nullptr && tort != nullptr && hare->next != nullptr){
            tort = tort->next;
            hare = hare->next->next;

            if(hare == tort){
                tort = head;

                while(tort != hare){
                    tort = tort->next;
                    hare = hare->next;
                }

                return tort;
            }
        }

        return nullptr;       
    }
};

int main(){
    vector<int> ts1 = {3, 2, 0, -4};
    int pos_ts1 = 1;

    vector<int> ts2 = {1, 2};
    int pos_ts2 = 0;
    
    ListNode* test_case_1 = nullptr;
    ListNode* test_case_2 = nullptr;

    int i = 0;
    ListNode* head = nullptr;
    ListNode* toLoopTo = nullptr;

    for (auto el = ts1.rbegin(); el != ts1.rend(); ++el){
        ListNode* tmp = new ListNode(*el, test_case_1);
        test_case_1 = tmp;

        if (i == 0)
            head = tmp;

        if (i == ts1.size() - pos_ts1 - 1)
            toLoopTo = tmp;

        i++;
    }

    head->next = toLoopTo;

    i = 0;
    head = nullptr;
    toLoopTo = nullptr;

    for (auto el = ts2.rbegin(); el != ts2.rend(); ++el){
        ListNode* tmp = new ListNode(*el, test_case_2);
        test_case_2 = tmp;

        if (i == 0)
            head = tmp;

        if (i == ts2.size() - pos_ts2 - 1)
            toLoopTo = tmp;

        i++;
    }

    head->next = toLoopTo;

    Solution test;
    cout << test.detectCycle(test_case_1)->val << endl;
    cout << test.detectCycle(test_case_2)->val << endl;
}