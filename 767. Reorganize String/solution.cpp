#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        map<char, int> count;

        for (auto el : s){
            count[el]++;
        }

        cout << s.size() << endl;

        while (ans.size() != s.size()){
            for (auto it = count.begin(); it != count.end(); ++it){
                if (ans.size() > 0 && ans[ans.size() - 1] == it->first){
                    return "";
                }

                if (it->second == 0){
                    continue;
                }

                ans += it->first;
                it->second--;

                if (it->second != 0 && it->second % 2 == 0){
                    auto temp = it;
                    it++;

                    while (it->second == 0){
                        it++;
                    }

                    if (it == temp)
                        return "";

                    ans += it->first;
                    it->second--;
                    it = temp;
                    it--;
                }
            }
        }

        return ans;
    }
};

int main(){
    Solution test;

    cout << test.reorganizeString("vvvlo") << endl;
}