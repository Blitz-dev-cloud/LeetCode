class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int chunkSize = sqrt(n);
        if (chunkSize == 0) chunkSize = 1;
        int chunks = (n + chunkSize - 1) / chunkSize;

        vector<int> chunkMaxVal(chunks);
        vector<bool> chunkDirty(chunks, false);

        auto updateChunkMax = [&](int chunkId) {
            int start = chunkId * chunkSize;
            int end = min(start + chunkSize, n);
            chunkMaxVal[chunkId] = 0;
            for (int i = start; i < end; i++) {
                chunkMaxVal[chunkId] = max(chunkMaxVal[chunkId], baskets[i]);
            }
            chunkDirty[chunkId] = false;
        };
        
        for (int i = 0; i < chunks; i++) {
            updateChunkMax(i);
        }
        
        int result = 0;
        
        for (int fruit : fruits) {
            bool assigned = false;
            
            for (int chunk = 0; chunk < chunks && !assigned; chunk++) {

                if (chunkDirty[chunk]) {
                    updateChunkMax(chunk);
                }

                if (chunkMaxVal[chunk] < fruit) continue;

                int start = chunk * chunkSize;
                int end = min(start + chunkSize, n);
                
                for (int i = start; i < end && !assigned; i++) {
                    if (baskets[i] >= fruit) {
                        baskets[i] = 0;
                        assigned = true;
                        chunkDirty[chunk] = true;
                    }
                }
            }
            
            if (!assigned) result++;
        }
        
        return result;
    }
};