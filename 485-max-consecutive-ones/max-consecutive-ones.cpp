class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int curr = 0, maxx = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(nums[i] == 1) {
                curr++;
                maxx = max(maxx, curr);
            } else curr = 0;
        }
        return maxx;
    }
};