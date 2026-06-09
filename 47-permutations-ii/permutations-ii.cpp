class Solution {
private:
    vector<vector<int>> result;
    void backtrack(int n, vector<int> &nums, vector<int> &curr, vector<bool> &visited) {

        if(curr.size() == n) {
            result.push_back(curr);
            return;
        }

        for( int i = 0 ; i < n ; i++ ) {
            if(visited[i]) continue;
            if(i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            
            curr.push_back(nums[i]);
            visited[i] = true;

            backtrack(n, nums, curr, visited);

            visited[i] = false;
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<bool> visited(n, false);
        backtrack(n, nums, curr, visited);
        return result;
    }
};