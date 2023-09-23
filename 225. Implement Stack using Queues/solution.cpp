#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q;

public:

    MyStack() {}
    
    void push(int x) {
        q.push(x);
        int size = q.size();
        while (size > 1){
            int temp = q.front();
            q.pop();
            q.push(temp);
            size--;
        }
    }
    
    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
