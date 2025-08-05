class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int count = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int j = 0;
            for( ; j < n ; j++ ) {
                if(baskets[j] >= fruits[i]) {
                    baskets[j] = 0;
                    break;
                }
            }
            if(j == n) count++;
        }
        return count;
    }
};