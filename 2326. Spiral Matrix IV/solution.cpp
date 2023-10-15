#include <iostream>
#include <vector>
#include "../printSmth.h"
#include "../ListNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int i = 0, j = 0, l = 0, r = n - 1, up = 0, down = m - 1, h_mul = 1, v_mul = 1;
        bool isHorizontal = true;
        vector<vector<int>> ans(m, vector<int>(n, -1));

        ListNode* temp = head;
        while (temp != nullptr){
            // cout << i << ' ' << j <<endl;
            ans[i][j] = temp->val;
            temp = temp->next;

            if (isHorizontal){
                if (h_mul == 1 && (j == l || j == r)){
                    isHorizontal = false;
                    i += h_mul;
                    h_mul = -h_mul;

                    if (j == r)
                        up += 1;
                    else
                        down -= 1;

                    continue;
                }

                j += h_mul;
            } else {
                if (v_mul == 1 && (i == down || i == up)){
                    isHorizontal = true;
                    j -= v_mul;
                    v_mul = -v_mul;

                    if (i == down)
                        r -= 1;
                    else
                        l += 1;
                    
                    continue;
                }

                i += v_mul;
            }
        }

        return ans;
    }
};

int main(){
    vector<int> ts1 = {0, 1, 2};
    ListNode* test_case_1 = nullptr;

    Solution test;
    for (auto el = ts1.rbegin(); el != ts1.rend(); ++el){
        ListNode* tmp = new ListNode(*el, test_case_1);
        test_case_1 = tmp;
    }

    auto res = test.spiralMatrix(1, 4, test_case_1);
    print2DVec(res);
}