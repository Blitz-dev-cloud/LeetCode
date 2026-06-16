class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int maxLen = 0;

        for( int r = 0 ; r < n ; r++ ){
            if(nums[r] == 0) k--;

            while(k < 0) {
                if(nums[l] == 0) k++;
                l++;
            }

            if(k >= 0) maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};