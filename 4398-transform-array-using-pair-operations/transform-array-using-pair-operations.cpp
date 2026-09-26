class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long s1 = accumulate(source.begin(), source.end(), 0LL);
        long long s2 = accumulate(target.begin(), target.end(), 0LL);
        return s1 == s2;
    }
};