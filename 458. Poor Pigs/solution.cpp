#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log2(buckets) / log2(minutesToTest / minutesToDie + 1));
    }
};
int main(){
    Solution test;

    cout << test.poorPigs(4, 15, 15) << endl;
}