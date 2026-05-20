class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<bool> visited(n + 1, 0);
        vector<int> result(n, 0);

        int r = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(A[i] == B[i]) {
                r++;
                result[i] = r;
            } else if(visited[A[i]] && visited[B[i]]) {
                r += 2;
            } else if(visited[A[i]] || visited[B[i]]) {
                r++;
            }
            visited[A[i]] = true;
            visited[B[i]] = true;
            result[i] = r;
        }

        return result;
    }
};