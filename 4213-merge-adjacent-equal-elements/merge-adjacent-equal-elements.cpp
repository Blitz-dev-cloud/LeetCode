class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<long long> st;

        for( int x : nums ) {
            st.push_back(1ll * x);

            while(st.size() >= 2 && st.back() == st[st.size() - 2]) {
                long long val = st.back();
                st.pop_back();
                st.pop_back();
                st.push_back(val * 2);
            }
        }

        return st;
    }
};