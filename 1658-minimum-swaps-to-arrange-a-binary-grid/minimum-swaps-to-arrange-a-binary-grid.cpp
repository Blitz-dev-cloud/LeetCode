class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<int> zeros;

        for( int i = 0 ; i < n ; i++ ) {
            int count = 0;
            for( int j = n - 1 ; j >= 0 && grid[i][j] == 0 ; j-- ) count++;
            zeros.push_back(count);
        }

        int swaps = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int needed_zeros = n - i - 1;
            int j = i;

            while(j < n && zeros[j] < needed_zeros) j++;

            if(j == n) return -1;

            swaps += (j - i);
            while(j > i) {
                swap(zeros[j], zeros[j - 1]);
                j--;
            }
        }

        return swaps;
    }
};