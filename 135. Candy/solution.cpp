#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int i = 1; 
        int candy = ratings.size();

        while (i < ratings.size()){
            if (ratings[i] == ratings[i - 1]){
                i++;
                continue;
            }

            int climb = 0;
            while (ratings[i] > ratings[i - 1]){
                climb++;
                candy += climb;
                i++;

                if (i == ratings.size())
                    return candy;
            }

            int slide = 0;
            while (i < ratings.size() && ratings[i] < ratings[i - 1]){
                slide++;
                candy += slide;
                i++;
            }

            candy -= min(climb, slide);

        }

        return candy;
    }
};

int main(){
    vector<int> test_case_1 = {1, 0, 2};
    vector<int> test_case_2 = {1, 2, 2};

    Solution test;

    cout << test.candy(test_case_1) << endl;
    cout << test.candy(test_case_2) << endl;
}