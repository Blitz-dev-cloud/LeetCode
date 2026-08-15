class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int xoredVal = nums[0];

        for( int i = 1 ; i < n ; i++ ) {
            xoredVal ^= nums[i];
        }

        if(xoredVal != 0) return n;

        for( int i = n - 1 ; i >= 0 ; i-- ) {
            int temp = xoredVal;
            if(temp ^ nums[i] != 0) return n - 1;
        }

        return 0;
    }
};