class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;

        for( int i = 0 ; i < s.size() ; i++ ) {
            unordered_map<char, int> freqMap;
            int distinct = 0;
            for( int j = i ; j < s.size() ; j++ ) {
                if(freqMap.count(s[j])) {
                    freqMap[s[j]]++;
                } else freqMap[s[j]] = 1;

                int cnt = freqMap[s[i]];
                int flag = 0, size = 0;

                for( auto& [c, f] : freqMap ) {
                    if(f != cnt) {
                        flag = 1;
                        break;
                    } 
                    size++;
                }

                if(!flag) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};