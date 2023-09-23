#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

    int helpFunc(string answerKey, int k, char pos){
        if (answerKey.size() == 1) {
            return 1;
        }

        int res = 0;

        int first_change = -1;

        int fst = 0, snd = 0;
        int cur_k = k;
        int len = 0;

        while (snd < answerKey.size()){

            //cout << "fst: " << fst << " " << answerKey[fst] << endl;
            //cout << "snd: " << snd << " " << answerKey[snd] << endl;

            if (pos != answerKey[snd]) {
                while (cur_k == 0) {

                    if (pos != answerKey[fst]) {
                        cur_k++;
                        fst++;
                        len--;
                        break;
                    }

                    fst++;
                    len--;
                }

                len++;
                cur_k--;
            } else {
                len++;
            }
            //cout << len << endl;
            res = max(len, res);

            snd++;
        }

        return res;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        int fst = helpFunc(answerKey, k, 'T');
        //cout << endl;
        int snd = helpFunc(answerKey, k, 'F');

        return max(fst, snd);
    }
};

int main(){
    string test_case_1 = "TTFF";
    string test_case_2 = "TFFT";
    string test_case_3 = "TTFTTFTT";
    string test_case_4 = "TF";
    string test_case_5 = "FFFTTFTTFT";

    Solution test;

    std::cout << test.maxConsecutiveAnswers(test_case_1, 2) << endl;
    std::cout << test.maxConsecutiveAnswers(test_case_2, 1) << endl;
    std::cout << test.maxConsecutiveAnswers(test_case_3, 1) << endl;
    std::cout << test.maxConsecutiveAnswers(test_case_4, 2) << endl;
    std::cout << test.maxConsecutiveAnswers(test_case_5, 3) << endl;
}