class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        for( int x : nums ) {
            if(seen.find(x) != seen.end()) return true;
            seen.insert(x);
        }
        return false;
    }
};