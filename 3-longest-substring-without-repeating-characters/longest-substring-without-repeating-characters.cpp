class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        unordered_map<char, int> seen;

        int result = 0;

        for( int r = 0 ; r < s.size() ; r++ ) {
            if(seen.count(s[r]) && seen[s[r]] >= l) {
                l = seen[s[r]] + 1;
            }
            seen[s[r]] = r;
            result = max(result, r - l + 1);
        }

        return result;
    }
};