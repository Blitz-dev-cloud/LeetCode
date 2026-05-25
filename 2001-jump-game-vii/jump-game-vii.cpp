class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
       int n = s.size();

       vector<bool> dp(n, false);
       dp[0] = true;

       int f = 0;
       for( int i = 1 ; i < n ; i++ ) {
        
        if(i - minJump >= 0 && dp[i - minJump]) f++;

        if(i - maxJump - 1 >= 0 && dp[i - maxJump - 1]) f--;

        if(f > 0 && s[i] == '0') dp[i] = true;
       }

       return dp[n - 1];
    }
};