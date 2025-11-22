class Solution {
public:
    int minimumFlips(int n) {
        string s = bitset<32>(n).to_string();

        int pos = s.find('1');
        s = s.substr(pos);
        //cout << s;

        int flips = 0;
        int L = s.size();

        for( int i = 0 ; i < L / 2 ; i++ ) {
            if(s[i] != s[L - 1 - i]) flips += 2;
        }

        return flips;
    }
};