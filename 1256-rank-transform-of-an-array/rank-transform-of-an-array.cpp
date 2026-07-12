class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> sortedArr;
        for( int i = 0 ; i < n ; i++ ) sortedArr.push_back({arr[i], i});

        sort(sortedArr.begin(), sortedArr.end());

        int r = 1;

        for( int i = 0 ; i < n ; i++ ) {
            arr[sortedArr[i].second] = r;
            if(i < n - 1 && sortedArr[i].first != sortedArr[i + 1].first) r++;
        }

        return arr;
    }
};