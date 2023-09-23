#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    void addNode(int n){
        ListNode* tmp = new ListNode(n);
        next = tmp;
    }

    void printList(){
        ListNode* tmp = this;

        while (tmp != nullptr){
            std::cout << tmp->val << ' ';
            tmp = tmp->next;
        }

        std::cout << std::endl;
    }
};