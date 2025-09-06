class Solution {
public:
    long long prefix(long long n) {
        if (n <= 0) return 0;
        
        long long res = 0;
        long long power = 1;
        int step = 1;

        while (power <= n) {
            long long next = power * 4;
            long long high = min(n, next - 1);
            long long cnt = high - power + 1;
            res += cnt * step;
            step++;
            power = next;
        }
        return res;
    }
    
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            long long totalSteps = prefix(r) - prefix(l - 1);
            long long ops = (totalSteps + 1) / 2;
            ans += ops;
        }
        return ans;
    }
};