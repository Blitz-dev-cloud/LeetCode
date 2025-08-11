class Solution {
private:
    static const int MOD = 1e9 + 7;

    long long modpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> powers;
        int bit = 0;
        int temp = n;
        while (temp > 0) {
            if (temp & 1) powers.push_back(1LL << bit);
            temp >>= 1;
            bit++;
        }

        int k = powers.size();
        vector<long long> prefix(k);
        prefix[0] = powers[0] % MOD;
        for (int i = 1; i < k; i++) {
            prefix[i] = (prefix[i - 1] * powers[i]) % MOD;
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto &q : queries) {
            int L = q[0], R = q[1];
            if (L == 0) {
                ans.push_back((int)prefix[R]);
            } else {
                long long inv = modpow(prefix[L - 1], MOD - 2);
                ans.push_back((int)((prefix[R] * inv) % MOD));
            }
        }

        return ans;
    }
};