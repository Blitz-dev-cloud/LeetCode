class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();

        int l = 0;
        int maxLen = INT_MIN;

        vector<int> freq(26, 0);

        for( int r = 0 ; r < n ; r++ ) {
            freq[s[r] - 'a']++;
            while(freq[s[r] - 'a'] > 2) {
                freq[s[l] - 'a']--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};