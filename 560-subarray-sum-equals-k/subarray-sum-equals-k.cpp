class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> preSum;
        preSum[0] = 1;
        int sum = 0, result = 0;

        for( int i = 0 ; i < nums.size() ; i++ ) {
            sum += nums[i];
            if(preSum.find(sum - k) != preSum.end()) {
                result += preSum[sum - k];
            }
            preSum[sum]++;
        }

        return result;
    }
};