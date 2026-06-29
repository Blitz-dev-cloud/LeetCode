class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int result = 0;

        for( string x : patterns ) {
            if(word.find(x) != string::npos) {
                result++;
            }
        }

        return result;
    }
};