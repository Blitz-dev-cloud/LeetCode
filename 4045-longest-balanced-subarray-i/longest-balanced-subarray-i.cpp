class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for( int l = 0 ; l < n ; l++ ) {
            unordered_map<int, int> oddFreq, evenFreq;
            int distinctOdd = 0, distinctEven = 0;

            for( int r = l ; r < n ; r++ ) {
                int x = nums[r];

                if(x % 2 == 0) {
                    if(++evenFreq[x] == 1) distinctEven++;
                } else {
                    if(++oddFreq[x] == 1) distinctOdd++;
                }

                if(distinctEven == distinctOdd) ans = max(ans, r - l + 1);
            }
        }

        return ans;
    }
};