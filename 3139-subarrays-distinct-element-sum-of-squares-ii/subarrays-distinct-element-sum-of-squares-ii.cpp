class Solution {
private:
    static const int MOD = 1e9 + 7;
    
    struct SegmentTree {
        int n;
        vector<long long> sum, sq, lazy;

        SegmentTree(int n): n(n), sum(4 * n), sq(4 * n), lazy(4 * n) {}

        void apply(int node, int l, int r, long long val) {
            long long len = r - l + 1;

            sq[node] = (sq[node] + 2LL * val % MOD * sum[node] % MOD + len % MOD * val % MOD * val % MOD) % MOD;

            sum[node] = (sum[node] + len * val) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
        }

        void push(int node, int l, int r) {
            if (lazy[node] == 0 || l == r) return;

            int mid = (l + r) / 2;

            apply(node * 2, l, mid, lazy[node]);
            apply(node * 2 + 1, mid + 1, r, lazy[node]);

            lazy[node] = 0;
        }

        void update(int node, int l, int r, int ql, int qr, long long val) {
            if (ql > r || qr < l) return;

            if (ql <= l && r <= qr) {
                apply(node, l, r, val);
                return;
            }

            push(node, l, r);

            int mid = (l + r) / 2;

            update(node * 2, l, mid, ql, qr, val);
            update(node * 2 + 1, mid + 1, r, ql, qr, val);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        }

        void update(int l, int r, long long val) {
            if (l <= r) update(1, 0, n - 1, l, r, val);
        }

        long long query() {
            return sq[1];
        }
    };

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        SegmentTree st(n);
        vector<int> last(100001, -1);

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            st.update(last[nums[i]] + 1, i, 1);

            last[nums[i]] = i;
            ans = (ans + st.query()) % MOD;
        }

        return ans;
    }
};