#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    int b_size;
    int b_0_size;

    bool find(vector<vector<char>>& board, string word, int i, int j, int x){
        if (x == word.size() - 1){
            return true;
        }

        if (i < 0 || i >= b_size || j < 0 || j >= b_0_size){
            return false;
        }

        if (board[i][j] != word[x] || board[i][j] == '1'){
            return false;
        }

        board[i][j] = '1';
        
        if (find(board, word, i, j + 1, x + 1) || find(board, word, i, j - 1, x + 1) ||
            find(board, word, i + 1, j, x + 1) || find(board, word, i - 1, j, x + 1)) {
                return true;
        }

        board[i][j] = word[x];

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        b_size = board.size();
        b_0_size = board[0].size();

        for (int i = 0; i < b_size; ++i){
            for (int j = 0; j < b_0_size; ++j){
                if (board[i][j] == word[0] && find(board, word, i, j, 0)){
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    vector<vector<char>> test_case_1 = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};

    Solution test;

    cout << test.exist(test_case_1, "ABCCED") << endl;
    cout << test.exist(test_case_1, "SEE") << endl;
    cout << test.exist(test_case_1, "ABCB") << endl;
}