class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> a(n, 0);
        vector<int> b(n, 0);
        vector<int> c(n, 0);

        a[0] = 0;
        b[0] = -prices[0];
        c[0] = INT_MIN;

        for( int i = 1 ; i < n ; i++ ) {
            a[i] = max(a[i - 1], c[i - 1]);
            b[i] = max(b[i - 1], a[i - 1] - prices[i]);
            c[i] = max(c[i - 1], b[i - 1] + prices[i]);
        }

        return max(a[n - 1], c[n - 1]);
    }
};