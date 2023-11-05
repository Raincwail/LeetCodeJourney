#include <iostream>
#include <vector>
#include <unordered_map>

#include "../TreeNode.h"
#include "../printSmth.h"

using namespace std;

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> counter;
        dfs(root, counter);
        int maxFreq = 0;

        for (auto res : counter) {
            maxFreq = max(maxFreq, res.second);
        }
        
        vector<int> ans;
        for (auto res : counter) {
            if (res.second == maxFreq) {
                ans.push_back(res.first);
            } 
        }
        
        return ans;
    }
    
    void dfs(TreeNode* node, unordered_map<int, int>& counter) {
        if (node == nullptr) {
            return;
        }

        counter[node->val]++;
        dfs(node->left, counter);
        dfs(node->right, counter);
    }
};

int main(){
    vector<int> test_case_vec = {1,NIL,2,2};
    TreeNode* test_case_1 = new TreeNode;

    test_case_1->createTree(test_case_vec);

    Solution test;

    auto res = test.findMode(test_case_1);
    printVec(res);
}