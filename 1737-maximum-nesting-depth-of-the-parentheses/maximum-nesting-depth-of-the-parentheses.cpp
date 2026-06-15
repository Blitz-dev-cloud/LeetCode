class Solution {
public:
    int maxDepth(string s) {
        int result = 0, sum = 0;

        for( char x : s ) {
            if(x == '(') {
                sum++;
                result = max(result, sum);
            }
            else if(x == ')') sum--;
        }

        return result;
    }
};