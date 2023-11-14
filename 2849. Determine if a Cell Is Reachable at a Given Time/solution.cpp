#include <iostream>

using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int width = abs(sx - fx);
        int height = abs(sy - fy);
        if (width == 0 && height == 0 && t == 1) {
            return false;
        }
        return t >= max(width, height);
    }
};
int main(){
    Solution test;

    cout << test.isReachableAtTime(2, 4, 7, 7, 6) << endl;
}