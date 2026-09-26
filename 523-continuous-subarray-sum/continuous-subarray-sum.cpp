class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        mp[0] = -1;

        long long prefix = 0;

        for( int i = 0 ; i < n ; i++ ) {
            prefix += nums[i];

            int r = prefix % k;

            if(mp.count(r)) {
                if(i - mp[r] >= 2) {
                    return true;
                }
            } else {
                mp[r] = i;
            }
        }

        return false;
    }
};