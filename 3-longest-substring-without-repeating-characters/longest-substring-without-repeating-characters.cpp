class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        int maxLen = 0, l = 0;

        for( int r = 0 ; r < s.size() ; r++ ) {
            while(seen.count(s[r])) {
                seen.erase(s[l]);
                l++;
            }
            seen[s[r]] = 1;
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};