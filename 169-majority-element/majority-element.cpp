class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> seen;
        for( int i = 0 ; i < n ; i++ ) {
            seen[nums[i]]++;
        }
        for( auto it : seen ) {
            if(it.second > n / 2) return it.first;
        }
        return -1;
    }
};