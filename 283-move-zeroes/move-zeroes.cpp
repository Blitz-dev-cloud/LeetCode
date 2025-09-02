class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;

        for( int i = 0 ; i < n ; i++ ) {
            if(nums[i] != 0) nums[l++] = nums[i];
        }

        for( int i = l ; i < n ; i++ ) nums[i] = 0;
    }
};