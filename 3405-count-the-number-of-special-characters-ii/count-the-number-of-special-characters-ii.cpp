class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();

        vector<int> l(26, -1), u(26, -1);

        for( int i = 0 ; i < n ; i++ ) {
            if(isupper(word[i])) {
                int idx = word[i] - 'A';
                if(u[idx] == -1) u[idx] = i;
            }
            if(islower(word[i])) {
                int idx = word[i] - 'a';
                l[idx] = i;
            }
        }

        int result = 0;
        for( int i = 0 ; i < 26 ; i++ ) {
            if(l[i] != -1 && u[i] != -1 && l[i] < u[i]) {
                result++;
            }
        }

        return result;
    }
};