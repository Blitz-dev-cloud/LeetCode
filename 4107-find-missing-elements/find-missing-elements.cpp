class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> results;
        sort(nums.begin(), nums.end());
        for( int i = 0 ; i < nums.size() - 1 ; i++ ) {
            int diff = nums[i + 1] - nums[i];
            int a = nums[i];
            while(diff > 1) {
                a++;
                results.push_back(a);
                diff--;
            }
        }
        return results;
    }
};