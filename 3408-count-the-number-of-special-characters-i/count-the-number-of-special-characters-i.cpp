class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        unordered_set<char> s;
        for( char w : word ) {
            if(isupper(w)) s.insert(w);
        }

        int result = 0;
        for( char w : word ) {
            if(islower(w) && !(s.find(w) != s.end())) {
                s.insert(w);
                char W = toupper(w);
                if(s.find(W) != s.end()) result++;
            }
        }

        return result;
    }
};