class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0, currProfit = prices[0];
        for( int i = 1 ; i < n ; i++ ) {
            int profit = prices[i] - currProfit;
            maxProfit = max(maxProfit, profit);
            currProfit = min(currProfit, prices[i]);
        }
        return maxProfit;
    }
};