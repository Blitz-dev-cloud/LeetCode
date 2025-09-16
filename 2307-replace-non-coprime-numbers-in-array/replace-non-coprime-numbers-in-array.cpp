class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st;

        for (int num : nums) {
            long long x = num;
            while (!st.empty()) {
                long long g = gcd(st.back(), x);
                if (g == 1) break;

                x = (st.back() * x) / g;
                st.pop_back();
            }
            st.push_back(x);
        }

        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};