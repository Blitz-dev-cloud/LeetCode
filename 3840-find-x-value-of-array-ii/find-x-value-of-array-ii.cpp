class Solution {
private:
    struct Node {
        int prod;
        int cnt[5] = {0, 0, 0, 0, 0};
    };
    vector<Node> seg;
    int K;

    void build(vector<int> &a, int idx, int low, int high) {
        if(low == high) {
            int r = a[low] % K;

            seg[idx].prod = r;
            seg[idx].cnt[r] = 1;

            return;
        }

        int mid = low + (high - low) / 2;
        build(a, 2 * idx + 1, low, mid);
        build(a, 2 * idx + 2, mid + 1, high);
        
        merge(idx);
    }

    void merge(int idx) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        seg[idx].prod = (seg[left].prod * seg[right].prod) % K;

        for( int r = 0 ; r < K ; r++ ) {
            seg[idx].cnt[r] = seg[left].cnt[r];
        }

        int leftProd = seg[left].prod;

        for( int r = 0 ; r < K ; r++ ) {
            int combinedR = (leftProd * r) % K;

            seg[idx].cnt[combinedR] += seg[right].cnt[r];
        }
    }

    void pointUpdate(int idx, int low, int high, int pos, int val) {
        if(low == high) {
            for( int i = 0 ; i < K ; i++ ) {
                seg[idx].cnt[i] = 0;
            }

            int r = val % K;
            seg[idx].prod = r;
            seg[idx].cnt[r] = 1;

            return;
        }

        int mid = low + (high - low) / 2;

        if(pos <= mid) pointUpdate(2 * idx + 1, low, mid, pos, val);
        else pointUpdate(2 * idx + 2, mid + 1, high, pos, val);

        merge(idx);
    }

    Node query(int idx, int low, int high, int l, int r) {
        if(low >= l && high <= r) {
            return seg[idx];
        }

        // if(r < low || l > high || low > high) return nullptr;

        int mid = low + (high - low) / 2;

        if(r <= mid) return query(2 * idx + 1, low, mid, l, r);
        if(l > mid) return query(2 * idx + 2, mid + 1, high, l, r);

        Node left = query(2 * idx + 1, low, mid, l, r);
        Node right = query(2 * idx + 2, mid + 1, high, l, r);

        Node res;
        res.prod = (left.prod * right.prod) % K;

        for( int i = 0 ; i < K ; i++ ) {
            res.cnt[i] = left.cnt[i];
        }

        int leftProd = left.prod;

        for( int i = 0 ; i < K ; i++ ) {
            int combinedR = (leftProd * i) % K;

            res.cnt[combinedR] += right.cnt[i];
        }

        return res;
    }
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();

        seg.resize(4 * n);
        K = k;

        build(nums, 0, 0, n - 1);

        int q = queries.size();
        vector<int> ans;

        for( int i = 0 ; i < q ; i++ ) {
            auto p = queries[i];
            int idx = p[0];
            int val = p[1];
            int l = p[2];
            int x = p[3];

            pointUpdate(0, 0, n - 1, idx, val);

            Node res = query(0, 0, n - 1, l, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};