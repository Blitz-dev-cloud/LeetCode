class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int index = 0, mlength = 0, marea = 0; 

        for( int i = 0 ; i < n ; i++ ) {
            int l = dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1];
            int area = dimensions[i][0] * dimensions[i][1]; 
            if(l > mlength || (l == mlength && area > marea)) {
                mlength = l;
                marea = area;
                index = i;
            }
            
        }

        return marea;
    }
};