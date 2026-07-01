class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen(nums.begin(), nums.end());
        int result = 0;

        for( auto &it : seen ) {
            if(seen.find(it - 1) == seen.end()) {
                int currNum = it;
                int length = 1;

                while(seen.find(currNum + 1) != seen.end()) {
                    currNum++;
                    length++;
                }

                result = max(result, length);
            }
        }

        return result;
    }
};