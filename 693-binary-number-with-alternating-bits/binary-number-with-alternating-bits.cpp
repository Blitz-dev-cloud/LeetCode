class Solution {
public:
    bool hasAlternatingBits(int n) {
        string bin = bitset<32> (n).to_string();
        bin = bin.substr(bin.find('1'));
        cout << bin;

        bool prevHigh = (bin[0] == '1' ? true : false);
        
        for( int i = 1 ; i < bin.size() ; i++ ) {
            if((prevHigh && bin[i] == '1') || (!prevHigh && bin[i] == '0')) return false;
            prevHigh = (bin[i] == '1' ? true : false);
        }

        return true;
    }
};