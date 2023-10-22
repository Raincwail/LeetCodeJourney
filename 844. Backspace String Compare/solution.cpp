#include <iostream>
#include <stack>

using namespace std;

class Solution {
private:
    void formStack(stack<char>& st, string s){
        for (char el: s){
            if (el == '#'){
                if (!st.empty())
                    st.pop();
                continue;
            }

            st.push(el);
        }
    }

public:
    bool backspaceCompare(string s, string t) {
        stack<char> a, b;
        
        formStack(a, s);
        formStack(b, t);

        return a == b;
    }
};

int main(){
    Solution test;

    cout << test.backspaceCompare("ab#c", "ad#c") << endl;
}