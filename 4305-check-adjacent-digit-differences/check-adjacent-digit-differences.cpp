class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.size();
        for( int i = 1 ; i < n ; i++ ) {
            //int d1 = s[i - 1] - '0';
            //int d2 = s[i] - '0';
            if(abs(s[i] - s[i - 1]) > 2) return false;
        }
        return true;
    }
};