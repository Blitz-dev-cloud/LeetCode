class Solution {
private:
    int dpf(int idx, int n, vector<int> &cost, vector<int> &dp) {
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int move1 = cost[idx] + dpf(idx + 1, n, cost, dp);
        int move2 = cost[idx] + dpf(idx + 2, n, cost, dp);
        return dp[idx] = min(move1, move2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(dpf(0, n, cost, dp), dpf(1, n, cost, dp));
    }
};