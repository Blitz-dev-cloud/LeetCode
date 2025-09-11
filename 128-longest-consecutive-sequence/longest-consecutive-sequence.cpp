class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for( int num : s ) {
            if(s.find(num - 1) == s.end()) {
                int currNum = num;
                int length = 1;

                while(s.find(currNum + 1) != s.end()) {
                    currNum++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};