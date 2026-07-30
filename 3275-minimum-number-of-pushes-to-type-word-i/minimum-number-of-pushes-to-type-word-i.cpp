class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        
        int factor = 0;
        int sum = 0;

        for( int i = 0 ; i < n ; i++ ) {
            if(i % 8 == 0) factor++;
            sum += factor;
        }

        return sum;
    }
};