class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums[0], r = nums[nums.size() - 1];

        vector<int> result;
        int j = 0;

        for( int i = l ; i <= r ; i++ ) {
            if(i == nums[j]) j++;
            else result.push_back(i);
        }

        return result;
    }
};