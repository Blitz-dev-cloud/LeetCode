class Solution {
    bool isVowel(char ch) {
        return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' 
        || ch == 'a' || ch == 'e' || ch == 'i' || ch =='o' || ch == 'u'; 
    }
public:
    string sortVowels(string s) {
        int n = s.size();

        vector<char> temp;

        for( char ch : s ) {
            if(isVowel(ch)) temp.push_back(ch);
        }

        sort(temp.begin(), temp.end());
        int j = 0;

        for( int i = 0 ; i < n ; i++ ) {
            if(isVowel(s[i])) s[i] = temp[j++];
        }

        return s;
    }
};