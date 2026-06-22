class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> freq;

        for( char x : text ) freq[x]++;

        int result = 0;

        while( freq['b'] >= 1 && freq['a'] >= 1 && freq['l'] >= 2 && freq['o'] >= 2 && freq['n'] >= 1) {
            result++;
            freq['b']--;
            freq['a']--;
            freq['l']-=2;
            freq['o']-=2;
            freq['n']--;
        }

        return result;
    }
};