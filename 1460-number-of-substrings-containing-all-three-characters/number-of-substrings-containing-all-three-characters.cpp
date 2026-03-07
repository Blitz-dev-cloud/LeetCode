class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, 0);
        int count = 0, l = 0;

        for( int r = 0 ; r < s.size() ; r++ ) {
            lastSeen[s[r] - 'a']++;
            while(lastSeen[0] > 0 && lastSeen[1] > 0 && lastSeen[2] > 0) {
                count += s.size() - r;
                lastSeen[s[l] - 'a']--;
                l++;
            }
        }

        return count;
    }
};