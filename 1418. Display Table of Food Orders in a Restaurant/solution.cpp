#include "../printSmth.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> res;
        set<string> foods;
        map<int, map<string, int>> diner;
        
        for (auto i: orders){
            foods.insert(i[2]);
            diner[stoi(i[1])][i[2]]++;
        }

        vector<string> firstLine;
        firstLine.push_back("Table");
        for (auto i: foods){
            firstLine.push_back(i);
        }
        
        res.push_back(firstLine);
        
        for (auto i: diner){
            vector<string> tmpLine;
            
            tmpLine.push_back(to_string(i.first));
            
            for (auto j: foods){
                
                if (i.second.find(j) != i.second.end()){
                    tmpLine.push_back(to_string(i.second[j]));
                }
                else
                    tmpLine.push_back("0");
            }
            
            res.push_back(tmpLine);
        }
        
        return res;
    }
};

int main(){
    vector<vector<string>> test_case_1 = {{"David","3","Ceviche"},{"Corina","10","Beef Burrito"},{"David","3","Fried Chicken"},{"Carla","5","Water"},{"Carla","5","Ceviche"},{"Rous","3","Ceviche"}};

    Solution test;

    auto res = test.displayTable(test_case_1);
    print2DVec(res);
}