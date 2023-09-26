#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
private:
    vector<int> vis;
    vector<int> letters = vector<int>(26);

    string helpFunc(string s){
        stack<char> st;
        
        st.push(s[0]);
        vis[s[0] - 'a'] = true;

        for (int i = 1; i < s.size(); ++i){
            char cur = s[i];
            if (!vis[cur - 'a']){
                char top = st.top(); 

                while (!st.empty() && top > cur && i < letters[top - 'a']){
                    vis[top - 'a'] = false;
                    st.pop(); top = !st.empty() ? st.top() : top; 
                }

                st.push(cur);
                vis[cur - 'a'] = true;
            }   
        }

        string res = "";
        while (!st.empty()){
            res += st.top(); st.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
public:
    string removeDuplicateLetters(string s) {
        vis = vector<int>(26, 0);        
        for (int i = 0; i < s.size(); ++i)
            letters[s[i] - 'a'] = i;

        return helpFunc(s);
    }
};

int main(){
    Solution test;

    cout << test.removeDuplicateLetters("bcabc") << endl;
    cout << test.removeDuplicateLetters("cbacdcbc") << endl;
}