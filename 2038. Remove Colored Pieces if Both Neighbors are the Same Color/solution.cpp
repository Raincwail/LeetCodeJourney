#include <iostream>

using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
        int n = colors.size();
        
        for (int i = 1; i < n - 1; ++i){
            if (colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A'){
                a++;
                continue;
            }

            if (colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B'){
                b++;
            }
        }

        return a > b;
    }
};

int main(){
    Solution test;

    cout << test.winnerOfGame("AAABABB") << endl;
}