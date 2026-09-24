class BookMyShow {
private:
    struct Node {
        int mx;
        long long sum;
    };

    vector<Node> seg;
    // vector<int> a;
    int N;
    int M;

    void build(int idx, int low, int high) {
        if(low == high) {
            seg[idx].sum = M;
            seg[idx].mx = M;
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * idx + 1, low, mid);
        build(2 * idx + 2, mid + 1, high);

        seg[idx].sum = seg[2 * idx + 1].sum + seg[2 * idx + 2].sum;
        seg[idx].mx = max(seg[2 * idx + 1].mx, seg[2 * idx + 2].mx);
    }

    int gatherQuery(int idx, int low, int high, int k, int r) {
        if(low > r || seg[idx].mx < k) return -1;

        if(low == high) return low;

        int mid = low + (high - low) / 2;

        int left = gatherQuery(2 * idx + 1, low, mid, k, r);

        if(left != -1) return left;

        return gatherQuery(2 * idx + 2, mid + 1, high, k, r);
    }

    int findVal(int idx, int low, int high, int pos) {
        if(low == high) {
            return seg[idx].mx;
        }

        int mid = low + (high - low) / 2;

        if(pos <= mid) {
            return findVal(2 * idx + 1, low, mid, pos);
        }
        
        return findVal(2 * idx + 2, mid + 1, high, pos);
    }

    void pointUpdate(int idx, int low, int high, int pos, int taken) {
        if(low == high) {
            seg[idx].mx -= taken;
            seg[idx].sum -= taken;
            return;
        }

        int mid = low + (high - low) / 2;

        if(pos <= mid) {
            pointUpdate(2 * idx + 1, low, mid, pos, taken);
        } else {
            pointUpdate(2 * idx + 2, mid + 1, high, pos, taken);
        }

        seg[idx].sum = seg[2 * idx + 1].sum + seg[2 * idx + 2].sum;
        seg[idx].mx = max(seg[2 * idx + 1].mx, seg[2 * idx + 2].mx);
    }

    long long sumQuery(int idx, int low, int high, int l, int r) {
        if(low > r || high < l || low > high) return 0;

        if(low >= l && high <= r) return seg[idx].sum;

        int mid = low + (high - low) / 2;
        long long left = sumQuery(2 * idx + 1, low, mid, l, r);
        long long right = sumQuery(2 * idx + 2, mid + 1, high, l, r);

        return left + right;
    }
public:
    BookMyShow(int n, int m) {
        // a.resize(n);
        seg.resize(4 * n);
        N = n;
        M = m;

        build(0, 0, N - 1);
    }
    
    vector<int> gather(int k, int maxRow) {
        int row = gatherQuery(0, 0, N - 1, k, maxRow);

        if(row == -1) return {};

        int freeSeats = findVal(0, 0, N - 1, row);

        int startSeat = M - freeSeats;

        pointUpdate(0, 0, N - 1, row, k);

        return {row, startSeat};
    }
    
    bool scatter(int k, int maxRow) {
        long long available = sumQuery(0, 0, N - 1, 0, maxRow);

        if(available < k) return false;

        while(k > 0) {
            int row = gatherQuery(0, 0, N - 1, 1, maxRow);

            int freeSeats = findVal(0, 0, N - 1, row);

            int taken = min(k, freeSeats);

            pointUpdate(0, 0, N - 1, row, taken);

            k -= taken;
        }

        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */