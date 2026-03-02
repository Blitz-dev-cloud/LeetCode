class Solution {
private:
    vector<vector<int>> res;
    void backtrack(int idx, vector<int> &candidates, vector<int> &curr, int target) {
        if(target == 0) {
            res.push_back(curr);
            return;
        }

        if(target < 0) return;

        for( int i = idx ; i < candidates.size() ; i++ ) {
            curr.push_back(candidates[i]);
            backtrack(i, candidates, curr, target - candidates[i]);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        backtrack(0, candidates, curr, target);
        return res;
    }
};