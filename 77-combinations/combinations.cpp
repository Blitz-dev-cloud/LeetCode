class Solution {
private:
    vector<vector<int>> result;
    void backtrack(int idx, int n, int k, vector<int> &A, vector<int> &curr) {

        if(curr.size() == k) {
            result.push_back(curr);
            return;
        }

        for( int i = idx ; i < n ; i++ ) {
            curr.push_back(A[i]);
            backtrack(i + 1, n, k, A, curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> A(n);
        int x = 1;
        for( int i = 0 ; i < n ; i++ ) A[i] = x++;
        vector<int> curr;
        backtrack(0, n, k, A, curr);
        return result;
    }
};