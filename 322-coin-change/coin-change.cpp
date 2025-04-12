class Solution {
public:
    //blitz
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;
        
        for( int i = 0 ; i < n ; i++ ){
            for( int j = coins[i] ; j <= amount ; j++ ){
                if(dp[j - coins[i]] != 1e9){
                    dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
                }
            }
        }

        return dp[amount] != 1e9 ? dp[amount] : -1;
    }
};