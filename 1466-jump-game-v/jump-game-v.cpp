class Solution {
private:
    int findMaxIndices(int idx, int n, vector<int> &arr, int d, vector<int> &dp) {
        if(dp[idx] != -1) return dp[idx];

        int maxCount = 1;

        for( int x = idx + 1 ; x <= min(n - 1, idx + d) ; x++ ) {
            if(arr[idx] <= arr[x]) break;
            maxCount = max(maxCount, 1 + findMaxIndices(x, n, arr, d, dp));
        }

        for( int x = idx - 1 ; x >= max(0, idx - d) ; x-- ) {
            if(arr[idx] <= arr[x]) break;
            maxCount = max(maxCount, 1 + findMaxIndices(x, n, arr, d, dp));
        }

        return dp[idx] = maxCount;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int result = 1;

        for( int i = 0 ; i < n ; i++ ) {
            result = max(result, findMaxIndices(i, n, arr, d, dp));
        }

        return result;
    }
};