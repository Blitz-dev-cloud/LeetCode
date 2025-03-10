class Solution {
public:
    //blitz
    void combination(int i, int n, int target, vector<int> &candidates, vector<int> &subset, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(subset);
            return;
        }

        for( int j = i ; j < n ; j++ ){
            if(j > i && candidates[j] == candidates[j - 1]) continue;
            if(candidates[j] > target) break;

            subset.push_back(candidates[j]);
            combination(j + 1, n, target - candidates[j], candidates, subset, ans);
            subset.pop_back();
        }        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        combination(0, candidates.size(), target, candidates, subset, ans);
        return ans;
    }
};