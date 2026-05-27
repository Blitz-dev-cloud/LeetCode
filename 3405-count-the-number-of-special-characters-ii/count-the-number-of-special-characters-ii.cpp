class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();

        unordered_map<char, int> l, u;

        for( int i = 0 ; i < n ; i++ ) {
            if(isupper(word[i]) && !u.count(word[i])) u[word[i]] = i;
            if(islower(word[i])) l[word[i]] = i;
        }

        int result = 0;
        for( auto& m : l ) {
            auto [key, value] = m;
            char K = toupper(key);
            if(u.count(K) && value < u[K]) result++;
        }

        return result;
    }
};