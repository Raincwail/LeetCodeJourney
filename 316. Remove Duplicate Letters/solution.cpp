#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

/* This solution is basically a DP solution
 The worst case scenario is O(n^n)
 Probably couldve been improved with memoization
 But still horrible */

/*class Solution {
private:
    string og;
    int res_size;
    vector<vector<int>> letters = vector<vector<int>>(26);

    string helpFunc(string toFind, int pos, string curStr){
        if (curStr.size() == res_size){
            return curStr;
        }

        for (int i = 0; i < toFind.size(); ++i){
            for (const auto& ind: letters[toFind[i] - 'a']){
                if (ind < pos){
                    continue;
                }

                string res = helpFunc(toFind.substr(0, i) + toFind.substr(i + 1), ind, curStr + og[ind]);
                if (res.size() == res_size)
                    return res;
            }
        }

        return "";
    }
public:
    string removeDuplicateLetters(string s) {
        og = s;

        set<char> tmp = set<char>(s.begin(), s.end());
        string toFind = "";
        for (auto el: tmp)
            toFind+=el;

        res_size = toFind.size();

        for (int i = 0; i < s.size(); ++i)
            letters[s[i] - 'a'].push_back(i);

        return helpFunc(toFind, 0, "");
    }
};*/

/* This a stack + greedy approach
   Lets create a string of UNIQUE characters
   In a lexicographical order
   
   Something of an example: "cbacdcbc"
   1. St: "cb" Ch: 'a' -> St: "a" (popped everything more than 'a')
   2. St: "acd" Ch: 'b' -> St: "acdb" (since 'd' does not appear later we do not pop it)
   3. Res = "acdb" 
*/
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