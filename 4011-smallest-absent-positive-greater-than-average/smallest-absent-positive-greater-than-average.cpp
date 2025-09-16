class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for( int i = 0 ; i < n ; i++ ) {
            sum += nums[i];
        }
        int key = sum / n + 1;
        if(key <= 0) key = 1;
        unordered_set<int> st(nums.begin(), nums.end());
        while (st.count(key)) {
            key++;
        }
        return key;
    }
};