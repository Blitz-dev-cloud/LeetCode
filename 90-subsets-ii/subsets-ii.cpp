class Solution {
public:
    //blitz
    void find_subsets(int i, vector<int> &nums, vector<int> subset, vector<vector<int>> &ans){
        if(i == nums.size()){
            if(!(find(ans.begin(), ans.end(), subset) != ans.end())){
                ans.push_back(subset);
            }
            return;
        }

        subset.push_back(nums[i]);
        find_subsets(i + 1, nums, subset, ans);

        subset.pop_back();
        find_subsets(i + 1, nums, subset, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        find_subsets(0, nums, subset, ans);
        return ans;
    }
};