class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();

        if(n < k) return false;

        int total = (1 << k);
        if(n - k + 1 < total) return false;

        unordered_set<int> seen;
        int num = 0;
        int mask = total - 1;

        for( int i = 0 ; i < s.size() ; i++ ) {
            num = ((num << 1 & mask) | s[i] - '0');

            if(i >= k - 1) {
                seen.insert(num);
                if(seen.size() == total) return true;
            }
        }

        return false;
    }
};