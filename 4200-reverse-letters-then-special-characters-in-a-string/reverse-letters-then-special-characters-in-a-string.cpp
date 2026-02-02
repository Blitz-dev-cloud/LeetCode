class Solution {
public:
    string reverseByType(string s) {
        string letters, spChars;

        for( char c : s ) {
            if(c >= 'a' && c <= 'z') letters.push_back(c);
            else spChars.push_back(c);
        }

        int i = 0, j = 0;
        reverse(letters.begin(), letters.end());
        reverse(spChars.begin(), spChars.end());

        for( char &c : s ) {
            if(c >= 'a' && c <= 'z') c = letters[i++];
            else c = spChars[j++];
        }

        return s;
    }
};