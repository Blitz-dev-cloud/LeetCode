class Solution {
public:
    int minRotations(string s) {
        int n = s.size();

        int ans = min(s[0] - '0', 10 - (s[0] - '0'));

        for( int i = 1 ; i < n ; i++ ) {
            int x = s[i] - '0';
            int y = s[i - 1] - '0';
            int d = abs(x - y);
            ans += min(d, 10 - d);
        }

        return ans;
    }
};