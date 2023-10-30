#include <iostream>
#include <limits.h>
#include <algorithm>
#include "../TreeNode.h"
#include "../printSmth.h"

using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr)
            return {};
        
        vector<int> ans;

        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()){
            int size = q.size();
            int maxNode = INT_MIN;

            while (size--){
                TreeNode* tmp = q.front();
                q.pop();

                if (maxNode < tmp->val)
                    maxNode = tmp->val;
            
                if (tmp->left != nullptr)
                    q.push(tmp->left);

                if (tmp->right != nullptr)
                    q.push(tmp->right);
            }

            ans.push_back(maxNode);
        }

        return ans;
    }
};

int main(){
    vector<int> test_case_vec = {1,3,2,5,3,NIL,9};
    TreeNode* test_case_1 = new TreeNode;

    test_case_1->createTree(test_case_vec);
    // test_case_1->printTree();

    Solution test;

    auto res = test.largestValues(test_case_1);
    printVec(res);
}