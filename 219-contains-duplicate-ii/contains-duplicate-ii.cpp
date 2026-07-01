class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> seen;
        for( int i = 0 ; i < n ; i++ ) {
            if(seen.count(nums[i])) {
                if(abs(i - seen[nums[i]]) <= k) return true;
            }
            seen[nums[i]] = i;
        }
        return false;
    }
};