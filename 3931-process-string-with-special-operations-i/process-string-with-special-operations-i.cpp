class Solution {
public:
    string processStr(string s) {
        string result = "";

        for( char x : s ) {
            if(islower(x)) result += x;
            else if(x == '*' && result.size() > 0) result.pop_back();
            else if(x == '#') result += result;
            else if(x == '%') reverse(result.begin(), result.end());
        }

        return result;
    }
};