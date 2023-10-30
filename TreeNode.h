#include <queue>
#include <iostream>

#define NIL 11037

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    void createTree(const std::vector<int>& vec){
        if (vec.empty()){
            return;
        }

        int ind = 0;
        TreeNode* tmp = this;
        tmp->val = vec[ind++];

        std::queue<TreeNode*> q;
        q.push(tmp);

        while (!q.empty() && ind < vec.size()){
            int size = q.size();
            while (size--){
                TreeNode* cur = q.front(); q.pop();

                if (vec[ind++] != NIL){
                    cur->left = new TreeNode(vec[ind - 1]);
                    q.push(cur->left);
                }

                if (vec[ind++] != NIL){
                    cur->right = new TreeNode(vec[ind - 1]);
                    q.push(cur->right);
                }
            }
        }
    }

    void printTree(){
        TreeNode* tmp = this;

        std::queue<TreeNode*> q;
        q.push(tmp);

        while (!q.empty()){
            int size = q.size();

            while (size--){
                TreeNode* cur = q.front(); q.pop();

                if (cur->val == NIL){
                    std::cout << "null ";
                    continue;
                }

                std::cout << cur->val << ' ';

                q.push(cur->left  != nullptr ? cur->left  : new TreeNode(NIL));
                q.push(cur->right != nullptr ? cur->right : new TreeNode(NIL));
            }

            std::cout << std::endl;
        }
    }
};