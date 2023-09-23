#include <vector>
#include <string>
#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:

    bool isSub(string first, string second)
    {
        // base case: an empty string is a subsequence of any string
        if (second.empty()) {
            return true;
        }
    
        // index for the next character of the second string
        int i = 0;
    
        // iterate over each character of the first string
        for (char c: first)
        {
            // if the current character matches the next character of the second string
            if (c == second[i])
            {
                // return true if we reach end of the second string
                if (++i == second.length()) {
                    return true;
                }
            }
        }
    
        // we reach here only if second string is not a subsequence of first string
        return false;
    }

    int numberOfUniqueGoodSubsequences(string binary) {
        long long res = 0;
        vector<string> substring = {"0", "1"};
        vector<string> new_substring;

        for (int len = 1; len <= binary.size(); len++){
            for (auto check: substring){

                if (isSub(binary, check)) {
                    res += 1;
                }
                
                if (check[0] != '0'){
                    new_substring.push_back(check + '0');
                    new_substring.push_back(check + '1');
                }
            }

            cout << endl;

            substring = new_substring;
            new_substring.clear();
        }

        return res;
    }

    int numberOfUniqueGoodSubsequences2(string binary) {
        long long res = 0;
        
        const char* bin = binary.c_str();
        char* pEnd;
        long long num =  strtoull (bin, &pEnd, 2);

        for (size_t i = 0; i <= num; ++i){
            string check = bitset<8>(i).to_string();

            std::size_t start = check.find('1');
            
            if (start == string::npos){
                start = check.size() - 1;
            }

            if (isSub(binary, check.substr(start))) {
                    res += 1;
            }
        }
        
        return res;
    }

};

int main(){

    string test_case_1 = "001";
    string test_case_2 = "11";
    string test_case_3 = "101";

    Solution test;

    std::cout << test.numberOfUniqueGoodSubsequences2(test_case_1) << endl;
    std::cout << test.numberOfUniqueGoodSubsequences2(test_case_2) << endl;
    std::cout << test.numberOfUniqueGoodSubsequences2(test_case_3) << endl;

}
