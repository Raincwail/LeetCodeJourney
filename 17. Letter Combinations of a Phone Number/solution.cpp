#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void print2DVec(vector<string>& toPrint){
    for (auto vec: toPrint){
        for (auto el: vec){
            cout << el << ' ';
        }
        cout << endl;
    }
}

class Solution {
public:

    unordered_map<char, string> digToLet = { {'2', "abc"}, {'3', "def"},
                                             {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
                                             {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    void helpFucn(string toUse, string curStr, int curN, int n, vector<string>& res){
        if (curN == n){
            res.push_back(curStr);
            return;
        }

        string let = digToLet[toUse[curN]];
        for (char el : let){
            helpFucn(toUse, curStr + el, curN + 1, n, res);
        }
    }

    vector<string> letterCombinations(string digits) {
        string temp = "";
        vector<string> res;

        helpFucn(digits, temp, 0, digits.size(), res);

        return res;
    }
};

int main(){
    Solution test;
    vector<string> toPrint;

    toPrint = test.letterCombinations("23");
    print2DVec(toPrint);

    toPrint = test.letterCombinations("");
    print2DVec(toPrint);

    toPrint = test.letterCombinations("2");
    print2DVec(toPrint);
}