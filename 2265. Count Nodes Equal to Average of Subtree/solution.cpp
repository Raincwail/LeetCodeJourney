#include <iostream>
#include <vector>

#include "../TreeNode.h"

using namespace std;

class Solution {
private:
    int ans = 0;

    pair<int, int> helpFunc(TreeNode* root){
        if (root == NULL)
            return {0, 0};

        pair<int, int> l, r;

        l = helpFunc(root->left);
        r = helpFunc(root->right);

        int sum = l.first + r.first + root->val;
        int num = l.second + r.second + 1;
        
        if (sum / num == root->val)
            ans++;

        return {sum, num};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        helpFunc(root);
        return ans;        
    }
};

int main(){
    vector<int> test_case_vec = {4,8,5,0,1,NIL,6};
    TreeNode* test_case_1 = new TreeNode;

    test_case_1->createTree(test_case_vec);


    Solution test;

    cout << test.averageOfSubtree(test_case_1) << endl;
}