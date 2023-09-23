#include "../ListNode.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* iter = head;

        while (iter){
            len++;
            iter = iter->next;
        }

        vector<int> subListLen;
        int fill = len % k;
        if (len / k){
            int i = 0;
            subListLen = vector<int>(k, len/k);
            while (fill--){
                subListLen[i++] += 1;
            }
        } else {
            subListLen = vector<int>(fill, 1);
        }

        int subListIter = 0;
        iter = head;

        vector<ListNode*> ans;
        while (subListIter != k){
            if (subListIter >= subListLen.size()){
                ans.push_back(nullptr);
                subListIter++;
                continue;
            }

            ListNode* temp = iter;
            int subList = subListLen[subListIter] - 1;
            while (subList--){
                iter = iter->next;
            }
            
            ListNode* finish = iter;
            if (iter){
                iter = iter->next;
                finish->next = nullptr;
            }
            
            ans.push_back(temp);
            subListIter++;
        }

        return ans;
    }
};
int main(){
    vector<int> ts1 = {1, 2, 3};
    vector<int> ts2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode* test_case_1 = nullptr;
    ListNode* test_case_2 = nullptr;
    vector<ListNode*> test_case_res;

    Solution test;
    for (auto el = ts1.rbegin(); el != ts1.rend(); ++el){
        ListNode* tmp = new ListNode(*el, test_case_1);
        test_case_1 = tmp;
    }

    for (auto el = ts2.rbegin(); el != ts2.rend(); ++el){
        ListNode* tmp = new ListNode(*el, test_case_2);
        test_case_2 = tmp;
    }

    test_case_res = test.splitListToParts(test_case_1, 5);
    for (auto el : test_case_res){
        el->printList();
    }

}