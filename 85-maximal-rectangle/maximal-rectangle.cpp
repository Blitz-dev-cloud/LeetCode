class Solution {
private:
    int maxRectangle(vector<int> &height) {
        int n = height.size();

        int result = 0;

        stack<int> st;

        for( int i = 0 ; i <= n ; i++ ) {
            while(!st.empty() && (i == n || height[st.top()] >= height[i])) {
                int h = height[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();

                int width = i - left - 1;

                result = max(result, h * width);
            }

            st.push(i);
        }

        return result;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);

        int result = 0;

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }

            result = max(result, maxRectangle(height));
        }

        return result;
    }
};