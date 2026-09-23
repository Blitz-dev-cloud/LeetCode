class NumArray {
private:
    vector<int> seg;
    int N;

    void build(vector<int> &nums, int idx, int low, int high) {
        if(low == high) {
            seg[idx] = nums[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(nums, 2 * idx + 1, low, mid);
        build(nums, 2 * idx + 2, mid + 1, high);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void pointUpdate(int idx, int low, int high, int pos, int val) {
        if(low == high) {
            seg[idx] = val;
            return;
        }

        int mid = low + (high - low) / 2;

        if(pos <= mid) pointUpdate(2 * idx + 1, low, mid, pos, val);
        else pointUpdate(2 * idx + 2, mid + 1, high, pos, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int rangeQuery(int idx, int low, int high, int l, int r) {
        if(low >= l && high <= r) {
            return seg[idx];
        }

        if(low > r || high < l || low > high) return 0;

        int mid = low + (high - low) / 2;
        int left = rangeQuery(2 * idx + 1, low, mid, l, r);
        int right = rangeQuery(2 * idx + 2, mid + 1, high, l, r);

        return left + right;
    }
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        seg.resize(4 * n);
        N = n;

        build(nums, 0, 0, N - 1);
    }
    
    void update(int index, int val) {
        pointUpdate(0, 0, N - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return rangeQuery(0, 0, N - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */