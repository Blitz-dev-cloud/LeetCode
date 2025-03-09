class Solution {
public:
    //blitz
    void find_subsets(int i, vector<int> &nums, vector<int> &subset, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        find_subsets(i + 1, nums, subset, ans);

        subset.pop_back();
        find_subsets(i + 1, nums, subset, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        int n = nums.size();
        find_subsets(0, nums, subset, ans);
        return ans;
    }
};