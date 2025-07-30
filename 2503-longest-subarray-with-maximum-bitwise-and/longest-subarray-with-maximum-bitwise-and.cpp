class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //vector<int> arr;
        int maxVal = *max_element(nums.begin(), nums.end());
        int currLen = 0, longest = 0;

        for( int num : nums ) {
            if(num == maxVal) {
                currLen++;
                longest = max(longest, currLen);
            } else {
                currLen = 0;
            }
        }

        return longest;
    }
};