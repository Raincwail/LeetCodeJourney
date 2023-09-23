#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max = 0;
        for (auto i: sentences){
            max < count(i.begin(), i.end(), ' ') ? max = count(i.begin(), i.end(), ' ') : max = max;
        }
        return max + 1;
        
    }
};

int main(){
    vector<string> test_case_1 = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};

    Solution test;

    cout << test.mostWordsFound(test_case_1) << endl;
}