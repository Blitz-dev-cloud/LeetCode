class Solution {
public:
    //blitz
    void combination_sum(int i, int n, int target, vector<int>& candidates, vector<int> &subset, vector<vector<int>> &ans){
        if(i == n){
            if(target == 0){
                ans.push_back(subset);
            }
            return;
        }

        if(candidates[i] <= target){
            subset.push_back(candidates[i]);
            combination_sum(i, n, target - candidates[i], candidates, subset, ans);
            subset.pop_back();
        }
        combination_sum(i + 1, n, target, candidates, subset, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        combination_sum(0, candidates.size(), target, candidates, subset, ans);
        return ans;
    }
};