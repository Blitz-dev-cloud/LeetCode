class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        map<int, int> freq;
        for( int num : nums ) freq[num]++;

        while(ans.size() < n) {
            for( auto &it : freq ) {
                auto [key, value] = it;
                if(freq[key] != 0) {
                    ans.push_back(key);
                    freq[key]--;
                }
            }
        }

        return ans;
    }
};