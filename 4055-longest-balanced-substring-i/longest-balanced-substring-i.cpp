class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;

        for( int i = 0 ; i < s.size() ; i++ ) {
            vector<int> freq(26, 0);
            int distinct = 0;
            for( int j = i ; j < s.size() ; j++ ) {
                freq[s[j] - 'a']++;

                int minFreq = INT_MAX, maxFreq = 0;

                for( int k = 0 ; k < 26 ; k++ ) {
                    if(freq[k] > 0) {
                        minFreq = min(minFreq, freq[k]);
                        maxFreq = max(maxFreq, freq[k]);
                    }
                }

                if(minFreq == maxFreq) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};