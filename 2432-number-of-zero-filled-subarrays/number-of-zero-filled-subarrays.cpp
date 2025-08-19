class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        //int n = nums.size();
        long long count = 0, curr = 0;

        for( int num : nums ) {
            if(num == 0) {
                curr++;
                count += curr;
            } else curr = 0;
        }

        return count;
    }
};