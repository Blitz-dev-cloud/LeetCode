class NumArray {
private:
    vector<int> bit;
    vector<int> arr;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        bit.assign(n + 1, 0);
        arr.assign(n, 0);

        for( int i = 0 ; i < n ; i++ ) {
            update(i, nums[i]);
        }

        for( int i = 0 ; i <= n ; i++ ) cout << bit[i] << " ";
        cout << endl;
    }
    
    void update(int index, int val) {
        int delta  = val - arr[index];
        arr[index] = val;

        index++;
        while(index <= n) {
            bit[index] += delta;
            index += index & (-index);
        }
    }

    int indexSum(int index) {
        index++;
        int s = 0;
        while( index > 0) {
            s += bit[index];
            index -= index & (-index);
        }
        return s;
    }
    
    int sumRange(int left, int right) {
        return indexSum(right) - indexSum(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */