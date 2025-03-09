class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), count = 0, max_count = 0;
        for( int i = 0 ; i < n ; i++ ){
            if(nums[i] == 1){
                count += 1;
                max_count = max(max_count, count);
            } else{
                count = 0;
            }
        }
        return max_count;
    }
};