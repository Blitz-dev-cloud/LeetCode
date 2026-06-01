class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> freq;
        
        int result = 0;
        while(n > 0) {
            int r = n % 10;
            freq[r]++;
            n /= 10;
        }

        for( auto& f : freq ) {
            auto [key, value] = f;
            result += key * value;
        }
        
        return result;
    }
};