class Solution {
public:
    //blitz
    void f(int ind, int k, int n, vector<int> &nums, vector<int> &sol, vector<vector<int>> &arr){
        if(sol.size() == k){
            int sum = 0;
            for( int i = 0 ; i < k ; i++ ){
                sum += sol[i];
            }
            if(sum == n){
                arr.push_back(sol);
            }
            return;
        }

        for( int i = ind ; i < nums.size() ; i++ ){
            sol.push_back(nums[i]);
            f(i + 1, k, n, nums, sol, arr);
            sol.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> sol;
        vector<int> nums;
        vector<vector<int>> arr;
        for( int i = 1 ; i <= 9 ; i++ ){
            nums.push_back(i);
        }
        f(0, k, n, nums, sol, arr);
        return arr;
    }
};