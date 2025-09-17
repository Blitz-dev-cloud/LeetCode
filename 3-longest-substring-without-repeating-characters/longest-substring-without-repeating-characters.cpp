class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        int l = 0, maxLen = 0;

        for( int r = 0 ; r < s.size() ; r++ ) {
            while(seen.count(s[r])) {
                seen.erase(s[l]);
                l++;
            }
            seen[s[r]]++;
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};