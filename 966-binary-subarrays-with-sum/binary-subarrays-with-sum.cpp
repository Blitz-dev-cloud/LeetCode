class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        int totalCount = 0, sum = 0;
        unordered_map<int, int> freqCount;
        for( int i = 0 ; i < n ; i++ ) {
            sum += nums[i];
            if(sum == goal) totalCount++;

            if(freqCount.find(sum - goal) != freqCount.end()) {
                totalCount += freqCount[sum - goal];
            }

            freqCount[sum]++;
        }

        return totalCount;
    }
};