class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for( char c : tasks ) freq[c - 'A']++;

        int maxFreq = *max_element(freq.begin(), freq.end());

        int maxCount = 0;
        for( int f : freq ) {
            if(f == maxFreq) maxCount++;
        }

        int parts = (maxFreq - 1) * (n + 1) + maxCount;

        return max((int)tasks.size(), parts);
    }
};
