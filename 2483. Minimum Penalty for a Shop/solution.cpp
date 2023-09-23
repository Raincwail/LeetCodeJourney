#include <iostream>

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;
        for (auto el : customers){
            penalty += el == 'Y' ? 1 : 0;
        }

        int min_penalty = penalty, min_pen_ind = 0; 

        for (int i = 1; i < customers.size() + 1; ++i){
            penalty += customers[i - 1] == 'Y' ? -1 : 1;
            if (min_penalty > penalty){
                min_penalty = penalty;
                min_pen_ind = i;
            }
        }

        return min_pen_ind;
    }
};

int main(){
    Solution test;

    cout << test.bestClosingTime("YYNY") << endl;
    cout << test.bestClosingTime("NNNNN") << endl;
    cout << test.bestClosingTime("YYYY") << endl;
}