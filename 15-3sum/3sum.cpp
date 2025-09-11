class Solution {
private:
    vector<vector<int>> kSumHelper(vector<int> &nums, int target, int k, int start) {
        vector<vector<int>> res;
        int n = nums.size();
        
        if(k == 2) {
            int l = start, r = n - 1;
            while( l < r ) {
                int sum = nums[l] + nums[r];
                if(sum == target) {
                    res.push_back({nums[l], nums[r]});
                    while( l < r && nums[l] == nums[l + 1] ) l++;
                    while( l < r && nums[r] == nums[r - 1] ) r--;
                    l++;
                    r--;
                } else if(sum < target) l++;
                else r--;
            }
            return res;
        }

        for( int i = start ; i < n - k + 1 ; i++ ) {
            if(i > start && nums[i] == nums[i - 1]) continue;

            vector<vector<int>> temp = kSumHelper(nums, target - nums[i], k - 1, i + 1);

            for(auto &vec : temp) {
                vec.insert(vec.begin(), nums[i]);
                res.push_back(vec);
            }
        }

        return res;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return kSumHelper(nums, 0, 3, 0);
    }
};