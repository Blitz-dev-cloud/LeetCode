class Solution {
private:
    unordered_map<long long, double> memo;
    
    long long getKey(int a, int b) {
        return ((long long)a << 32) | b;
    }

    double solve(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        
        long long key = getKey(a, b);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        double result = 0.25 * (
            solve(max(0, a - 100), b) +
            solve(max(0, a - 75), max(0, b - 25)) +
            solve(max(0, a - 50), max(0, b - 50)) +
            solve(max(0, a - 25), max(0, b - 75))
        );
        
        memo[key] = result;
        return result;
    }
public:
    double soupServings(int n) {
        if (n > 4800) return 1.0;
        
        return solve(n, n);
    }
};