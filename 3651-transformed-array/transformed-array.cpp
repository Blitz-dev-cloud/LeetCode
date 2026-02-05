class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n, 0);
        for( int i = 0 ; i < n ; i++ ) {
            if(nums[i] == 0) {
                temp[i] = nums[i];
            } else {
                int ni = ((i + nums[i]) % n + n) % n;
                temp[i] = nums[ni];
            }
        }
        return temp;
    }
};