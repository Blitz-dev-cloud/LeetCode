class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int prevGrp = 0, currGrp = 1;
        int res = 0;

        for( int i = 1 ; i < n ; i++ ) {
            if(s[i] == s[i - 1]) currGrp++;
            else {
                res += min(currGrp, prevGrp);
                prevGrp = currGrp;
                currGrp = 1;
            }
        }

        res += min(currGrp, prevGrp);

        return res;
    }
};