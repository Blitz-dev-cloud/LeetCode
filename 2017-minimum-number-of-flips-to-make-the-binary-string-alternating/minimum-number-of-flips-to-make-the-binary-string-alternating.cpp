class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;
        
        string s1 = "", s2 = "";

        for( int i = 0 ; i < 2 * n ; i++ ) {
            s1 += (i % 2 == 0) ? "0" : "1";
            s2 += (i % 2 == 0) ? "1" : "0";
        }

        int res = INT_MAX;
        int flip1 = 0, flip2 = 0;
        int l = 0;

        for( int r = 0 ; r < 2 * n ; r++ ) {
            if(s[r] != s1[r]) flip1++;
            if(s[r] != s2[r]) flip2++; 

            if(r - l + 1 > n) {
                if(s[l] != s1[l]) flip1--;
                if(s[l] != s2[l]) flip2--;
                l++;
            }

            if(r - l + 1 == n) res = min(res, min(flip1, flip2));
        }

        return res;
    }
};