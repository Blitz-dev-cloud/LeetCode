class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for( int i = 0 ; i < n ; i++ ) {
            int temp = __builtin_popcount(arr[i]);
            pq.push({temp, arr[i]});
        }

        int idx = 0;
        while(!pq.empty()) {
            arr[idx++] = pq.top().second;
            pq.pop();
        }

        return arr;
    }
};