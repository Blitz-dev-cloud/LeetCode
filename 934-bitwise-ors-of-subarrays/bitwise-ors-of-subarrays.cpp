class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        set<int> curr;
        for( int num : arr ) {
            set<int> currSet;
            currSet.insert(num);
            for( int val : curr ) {
                currSet.insert(val | num);
            }
            curr = currSet;
            for( int val : curr ) {
                result.insert(val);
            } 
        }
        return result.size();
    }
};