#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int edges = 0;
        vector<int> inDeg(n, 0);

        // Check if all nodes have exactly 1 parent
        for (int i = 0; i < n; ++i){
            if (leftChild[i] != -1){
                inDeg[leftChild[i]]++;

                if (inDeg[leftChild[i]] > 1) return false;
                edges++;
            }

            if (rightChild[i] != -1){
                inDeg[rightChild[i]]++;

                if (inDeg[rightChild[i]] > 1) return false;
                edges++;
            }
        }

        // Check if number of edges is n - 1
        if (edges != n - 1) return false;

        // Check if there is exactly 1 root
        int root = -1;
        for (int i = 0; i < n; ++i){
            if (inDeg[i] != 1){
                if (root == -1)
                    root = i;
                else
                    return false;
            }
        }


        // Check if all nodes can be visited from found root
        queue<int> q;
        q.push(root);

        int visitedNodes = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            visitedNodes++;

            if (leftChild[node] != -1)  q.push(leftChild[node]);
            if (rightChild[node] != -1) q.push(rightChild[node]);
        }

        return visitedNodes == n;
    }
};

int main(){
    vector<int> test_case_1_1 = {1, -1, 3, -1};
    vector<int> test_case_1_2 = {2, -1, -1, -1};

    Solution test;

    cout << test.validateBinaryTreeNodes(4, test_case_1_1, test_case_1_2) << endl;
}