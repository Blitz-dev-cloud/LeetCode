class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(2 * n, 0);

        for( int i = 0 ; i < n ; i++ ) {
            int val = nums[i];
            result[i] = val;
            result[2 * n - i - 1] = val;
        }

        return result;
    }
};