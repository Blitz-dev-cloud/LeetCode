class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            return make_pair(__builtin_popcount(a), a) <
                   make_pair(__builtin_popcount(b), b);
        });

        return arr;
    }
};