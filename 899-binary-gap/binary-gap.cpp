class Solution {
public:
    int binaryGap(int n) {
        bitset<32> b(n);
        string s = b.to_string().substr(b.to_string().find('1'));
        cout << s;

        int last = -1;
        int maxGap = 0;

        for( int i = 0 ; i < s.size() ; i++ ) {
            if(s[i] == '1') {
                if(last != -1) {
                    maxGap = max(maxGap, i - last);
                }
                last = i;
            }
        }

        return maxGap;
    }
};