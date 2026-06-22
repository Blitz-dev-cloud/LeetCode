class Solution {
private:
    set<int> result;

    void backtrack(int i, int n, int curr, vector<bool> &used, vector<int> &digits) {
        if(i == 3) {
            if(curr % 2 == 0) result.insert(curr);
            return;
        }

        for( int j = 0 ; j < n ; j++ ) {
            if(used[j]) continue;

            if(i == 0 && digits[j] == 0) continue;
            used[j] = true;
            backtrack(i + 1, n, curr * 10 + digits[j], used, digits);
            used[j] = false;
        }
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        int curr = 0;
        vector<bool> used(n, false);
        backtrack(0, n, curr, used, digits);
        return vector<int> (result.begin(), result.end());
    }
};