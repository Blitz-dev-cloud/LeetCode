class Solution {
private:
    vector<vector<int>> res;
    void backtrack(vector<int> &nums, vector<int> &curr, vector<bool> &used) {
        if(curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        for( int i = 0 ; i < nums.size() ; i++ ) {
            if(used[i]) continue;

            used[i] = true;
            curr.push_back(nums[i]);

            backtrack(nums, curr, used);

            used[i] = false;
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        backtrack(nums, curr, used);
        return res;
    }
};