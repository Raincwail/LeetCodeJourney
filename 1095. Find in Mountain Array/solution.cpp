#include <iostream>

using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
#include <iostream>
#include <vector>

class MountainArray{
private:
    vector<int> val;
public:
    MountainArray(vector<int> val){
        this->val = val;
    };

    int get(int index){
        return val[index];
    }

    int length(){
        return val.size();
    }
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = -1, size = mountainArr.length() - 1;    
        
        int st = 0, en = size;
        while (st <= en){
            int mid = st + (en - st) / 2;
            
            if (mid - 1 < 0){
                int m = mountainArr.get(mid), r = mountainArr.get(mid + 1);
                peak = m > r ? mid : mid + 1;
                break;
            }

            if (mid + 1 > size){
                int l = mountainArr.get(mid - 1), m = mountainArr.get(mid);
                peak = l > m ? mid - 1 : mid;
                break;
            }

            int l = mountainArr.get(mid - 1), m = mountainArr.get(mid), r = mountainArr.get(mid + 1);
            if (m > l && m > r){
                peak = mid;
                break;
            }

            if (m > l && r > m){
                st = mid;
                continue;   
            }

            if (l > m && m > r){
                en = mid;
                continue;
            }
        }
    
        st = 0, en = peak;        
        while (st <= en){
            int mid = st + (en - st) / 2;
            
            if (mountainArr.get(mid) == target){
                return mid;
            }   

            if (target > mountainArr.get(mid)){
                st = mid + 1;
            } else {
                en = mid - 1;
            }
        }

        st = peak + 1, en = size;
        while (st <= en){
            int mid = st + (en - st) / 2;
            
            if (mountainArr.get(mid) == target){
                return mid;
            }   

            if (target > mountainArr.get(mid)){
                en = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return -1;
    }
};

int main(){
    MountainArray test_case_1({1, 2, 3, 4, 5, 3, 1});

    Solution test;

    cout << test.findInMountainArray(3, test_case_1) << endl;
}