class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        for( int n : nums ) {
            if(count == 0) {
                candidate = n;
            }
            count += (n == candidate) ? 1 : -1;
        }
        return candidate;
    }
};