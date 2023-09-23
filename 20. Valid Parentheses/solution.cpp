#include <vector>
#include <stack>
#include <iostream>

using namespace std;

using ll = long long;

class Solution {
public:

    bool last(char el){
        return el == ')' || el == '}' || el == ']';
    }

    bool matching(char f, char s){
        return (f == '(' && s == ')') ||
               (f == '{' && s == '}') ||
               (f == '[' && s == ']');
    }

    bool isValid(string s) {
        stack<char> q;

        for (auto el: s){
            if (q.empty() && last(el)){
                return false;
            }

            if (!q.empty() && last(el)){
                char fr = q.top();

                cout << fr << ' ' << el << endl;

                if (!matching(fr, el)){
                    return false;
                }

                q.pop();

                continue;
            }

            q.push(el);
        }

        return q.empty();
    }
};

int main(){
    Solution test;

    cout << test.isValid("()") << endl;
    cout << test.isValid("()[]{}") << endl;
    cout << test.isValid("[(])") << endl;
}