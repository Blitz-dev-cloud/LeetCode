class Solution {
private:
    vector<int> bit;
    int n;

    void update(int idx, int val) {
        while(idx <= n) {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int s = 0;
        
        while(idx > 0) {
            s += bit[idx];
            idx -= idx & (-idx);
        }

        return s;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sorted(nums);

        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> rank;
        int r = 1;

        for( int x : sorted ) {
            if(!rank.count(x)) {
                rank[x] = r++;
            }
        }

        n = r + 2;
        bit.assign(n + 1, 0);

        int size = nums.size();
        vector<int> ans(size);

        for( int i = size - 1 ; i >= 0 ; i-- ) {
            int idx = rank[nums[i]];

            int val = query(idx - 1);

            ans[i] = val;
            update(idx, 1);
        }

        return ans;
    }
};