class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int cnt = 0;

        for( int i = 0 ; i < nums.size() - 1 ; i++ ) {
            int sum = 0, freq = 0;
            for( int j = i + 1 ; j < nums.size() ; j++ ) {
                sum += nums[j];
                freq++;
            }
            if(nums[i] > (sum / freq)) cnt++;
        }

        return cnt;
    }
};