class Solution {
public:
    //blitz
    static bool comp(const vector<int> &a, const vector<int> &b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), comp);

        int total_value = 0;

        for( int i = 0 ; i < n && truckSize > 0 ; i++ ){
            if(truckSize > boxTypes[i][0]){
                total_value += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            } else{
                total_value += truckSize * boxTypes[i][1];
                break;
            }
        }

        return total_value;
    }
};