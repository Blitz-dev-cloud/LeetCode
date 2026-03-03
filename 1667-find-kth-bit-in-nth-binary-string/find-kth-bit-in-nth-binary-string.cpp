class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";

        while(n-- > 1) {
            string inverted_s = "";
            for( int i = 0 ; i < s.size() ; i++ ) {
                if(s[i] == '1') inverted_s += '0';
                else inverted_s += '1';
            }
            s += '1';
            reverse(inverted_s.begin(), inverted_s.end());
            s += inverted_s;
        }

        return s[k - 1];
    }
};