class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        while(maxHeap.size() > 1) {
            int fmax = maxHeap.top();
            maxHeap.pop();
            int smax = maxHeap.top();
            maxHeap.pop();
            int diff = fmax - smax;
            if(diff > 0) maxHeap.push(diff);
        }

        return (maxHeap.size() == 0) ? 0 : maxHeap.top();
    }
};