class Solution {
public:
    int minPartitions(string n) {
        int maxInt = 0;
        for( int i = 0 ; i < n.size() ; i++ ) {
            int x = n[i] - '0';
            maxInt = max(maxInt, x);
        }
        return maxInt;
    }
};