class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> lastSeen(3, 0);

        int result = 0;
        int l = 0;

        for( int r = 0 ; r < n ; r++ ) {
            lastSeen[s[r] - 'a']++;
            while(lastSeen[0] > 0 && lastSeen[1] > 0 && lastSeen[2] > 0) {
                result += n - r;
                lastSeen[s[l] - 'a']--;
                l++;
            }
        }

        return result;
    }
};