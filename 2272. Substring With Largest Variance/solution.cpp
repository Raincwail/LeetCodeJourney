#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int largestVariance(string s) {
        set<char> elems_set(begin(s), end(s));
        int best_sum = 0;
        vector<char> elems;

        std::copy(elems_set.begin(), elems_set.end(), std::back_inserter(elems));
        
        for (int i = 0; i < elems.size(); ++i){
            for (int j = 0; j < elems.size(); ++ j){
                
                if (i == j) {
                    continue;
                }

                for (int k = 0; k < 2; ++k){
                    int a = 0, b = 0;
                    for (const auto el: s){
                        if (el == elems[i]){
                            a++;
                        }
                        
                        if (el == elems[j]){
                            b++;
                        }

                        if (a > b) {
                            a = 0, b = 0;
                        }

                        if (a > 0 && b > 0){
                            best_sum = max(best_sum, abs(a - b));
                        } 
                    }

                    reverse(s.begin(), s.end());
                }
            }
        }
        
        return best_sum;
    }
};

int main(){
    string test_case_1 = "aababbb";
    string test_case_2 = "abcde";
    string test_case_3 = "lripaa";
    string test_case_4 = "aabbbbaa";
    string test_case_5 = "baaa";
    
    Solution test;

    cout << test.largestVariance(test_case_1) << endl;
    cout << test.largestVariance(test_case_2) << endl;
    cout << test.largestVariance(test_case_3) << endl;
    cout << test.largestVariance(test_case_4) << endl;
    cout << test.largestVariance(test_case_5) << endl;
}