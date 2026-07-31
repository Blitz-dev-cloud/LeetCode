class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for( char x : word ) {
            freq[x - 'a']++;
        }

        sort(freq.rbegin(), freq.rend());

        int factor = 0;
        int sum = 0;

        for( int i = 0 ; i < freq.size() ; i++ ) {
            if(i % 8 == 0) factor++;
            sum += factor * freq[i];
        }

        return sum;
    }
};