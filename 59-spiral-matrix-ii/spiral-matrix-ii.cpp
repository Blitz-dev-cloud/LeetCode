class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;

        vector<vector<int>> matrix(n, vector<int> (n));
        int nums = 1;

        while(top <= bottom && left <= right) {
            for( int i = left ; i <= right ; i++ ) {
                matrix[top][i] = nums++;
            }
            top++;

            for( int i = top ; i <= bottom ; i++ ) {
                matrix[i][right] = nums++;
            }
            right--;

            if(top <= bottom) {
                for( int i = right ; i >= left ; i-- ) {
                    matrix[bottom][i] = nums++;
                }
                bottom--;
            }

            if(left <= right) {
                for( int i = bottom ; i >= top ; i-- ) {
                    matrix[i][left] = nums++;
                }
                left++;
            }
        }

        return matrix;
    }
};