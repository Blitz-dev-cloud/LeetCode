class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0], currMin = nums[0], result = nums[0];

        for( int i = 1 ; i < n ; i++ ) {
            if(nums[i] < 0) swap(currMin, currMax);

            currMin = min(nums[i], currMin * nums[i]);
            currMax = max(nums[i], currMax * nums[i]);

            result = max(result, currMax);
        }

        return result;
    }
};