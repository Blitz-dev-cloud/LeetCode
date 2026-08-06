class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> f;
        f[0] = -1;

        int sum = 0;
        int result = 0;

        for( int i = 0 ; i < n ; i++ ) {
            if(nums[i] == 1) {
                sum++;
            } else {
                sum--;
            }

            if(f.count(sum)) {
                result = max(result, i - f[sum]);
            } else {
                f[sum] = i;
            }
        }

        return result;
    }
};