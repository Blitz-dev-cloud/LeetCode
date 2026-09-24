class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for( int i = 0 ; i < n ; i++ ) {
            string num = to_string(nums[i]);
            int sum = 0;
            for( char c : num ) sum += c - '0';
            if(sum == i) return i;
        }

        return -1;
    }
};