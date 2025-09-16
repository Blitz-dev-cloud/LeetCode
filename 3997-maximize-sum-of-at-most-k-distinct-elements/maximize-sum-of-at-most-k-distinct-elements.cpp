class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        unordered_set<int> unique(nums.begin(), nums.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for( int num : unique ) {
            pq.push(num);
            if(pq.size() > k) pq.pop();
        }

        vector<int> res;

        while(!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};