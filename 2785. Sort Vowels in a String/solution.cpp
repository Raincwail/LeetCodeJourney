#include <iostream>

using namespace std;

class Solution {
private:
    bool isVowel(char a){
        return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a =='u' ||
        a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U';
    }

public:
    string sortVowels(string s) {
        int vowelCnt[128] = {0};

        for (int i = 0; i < s.size(); ++i)
            if (isVowel(s[i]))
                vowelCnt[(int)s[i]]++;

        int i = 0;
        for (int j = 0; j < s.size(); ++j)
            if (isVowel(s[j])) {
                while (vowelCnt[i] == 0) i++;
                s[j] = (char)i;
                vowelCnt[i]--;
            }

        return s;
    }
};

int main(){
    Solution test;

    cout << test.sortVowels("lEetcOde") << endl;
}