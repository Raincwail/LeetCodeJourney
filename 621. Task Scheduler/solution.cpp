#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0){
            return tasks.size();
        }

        priority_queue<pair<int, char>> tq;

        set<char> s(tasks.begin(), tasks.end());

        int i = 0;
        for (char el : s){
            int count = 0;
            for (char el_v : tasks){
                if (el == el_v)
                    count++;
            }
            tq.push({count, el});
        }

        int n_size = 0;
        int ans = 0;
        while (!tq.empty()){
           int window = n + 1;
            vector<pair<int, int>> temp;

            while (window && !tq.empty()){
                auto top = tq.top();
                tq.pop();

                top.first--;
                if (top.first > 0)
                    temp.push_back(top);

                window--;
                ans++;
            }

            for (auto el : temp)
                tq.push(el);

            if (tq.empty())
                break;

            ans += window;
        }

        return ans;
    }
};

int main(){
    vector<char> test_case_1 = {'A','A','A','B','B','B'};

    Solution test;

    cout << test.leastInterval(test_case_1, 2) << endl;
    cout << test.leastInterval(test_case_1, 0) << endl;
}