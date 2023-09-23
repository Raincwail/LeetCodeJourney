#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        string substring;

        for (int i = 0; i < s.size(); ++i){
            int cur_len = 1;
            substring = s[i];

            for (int j = i + 1; j < s.size(); ++j){
                if (substring.find(s[j]) != string::npos){
                    break;
                }

                substring += s[j];
                cur_len++;

            }
                    
            if (cur_len > res) res = cur_len;

        }

        return res;
    }

    int lengthOfLongestSubstring2(string s) {
        int res = 0;
        
        int fst = 0;
        int snd = 0;

        unordered_map<char, bool> cur_substr;
        for (const auto ch: s){
            cur_substr[ch] = false;
        }
        cur_substr[s[fst]] = true;

        while (snd < s.size()){
            snd++;

            if (snd - fst > res) res = snd - fst;

            if (cur_substr[s[snd]] == true) {
                while (cur_substr[s[snd]] == true){
                    cur_substr[s[fst]] = false;
                    fst++;
                }
            }

            cur_substr[s[snd]] = true;
        }
        
        return res;
    }

    int lengthOfLongestSubstring3(string s) {
        int res = 0;
        
        int fst = 0;
        int snd = 0;

        unordered_map<char, int> cur_substr;
        for (const auto ch: s){
            cur_substr[ch] = -1;
        }

        for (snd = 0; snd < s.size(); snd++){
            if (cur_substr[s[snd]] != -1 && cur_substr[s[snd]] >= fst) {
                fst = cur_substr[s[snd]] + 1;
            } else {
                res = max(res, snd - fst + 1);
            }

            cur_substr[s[snd]] = snd;
        }
        
        return res;
    }

};

int main(){
    string test_case_1 = "abcabcbb";
    string test_case_2 = "bbbbb";
    string test_case_3 = "pwwkew";
    string test_case_4 = " ";
    string test_case_5 = "";

    Solution test;

    std::cout << test.lengthOfLongestSubstring3(test_case_1) << endl;
    std::cout << test.lengthOfLongestSubstring3(test_case_2) << endl;
    std::cout << test.lengthOfLongestSubstring3(test_case_3) << endl;
    std::cout << test.lengthOfLongestSubstring3(test_case_4) << endl;
    std::cout << test.lengthOfLongestSubstring3(test_case_5) << endl;
}