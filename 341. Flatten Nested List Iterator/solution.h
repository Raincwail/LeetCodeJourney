/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    int it = 0;
    vector<int> nestedValues;

    void helpFunc(vector<NestedInteger> &nestedList){
        for (auto elem: nestedList){
            if (elem.isInteger()){
                nestedValues.push_back(elem.getInteger());
            } else {
                helpFunc(elem.getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        helpFunc(nestedList);
    }
    
    int next() {
        return nestedValues[it++];
    }
    
    bool hasNext() {
        return it < nestedValues.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */