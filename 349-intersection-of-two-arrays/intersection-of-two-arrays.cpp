class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        for( int x : nums1 ) freq[x]++;

        vector<int> ans;

        for( int x : nums2 ) {
            if(freq.count(x) && freq[x] != 0) {
                ans.push_back(x);
                freq[x] = 0;
            }
        }

        return ans;
    }
};