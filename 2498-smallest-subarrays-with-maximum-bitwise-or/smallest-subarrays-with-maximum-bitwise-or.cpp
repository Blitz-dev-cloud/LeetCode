class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        unordered_map<int, int> orMap;

        for (int i = n - 1; i >= 0; --i) {
            unordered_map<int, int> newOrMap;
            newOrMap[nums[i]] = 1;

            for (auto& [orVal, len] : orMap) {
                int newOr = orVal | nums[i];
                if (newOrMap.count(newOr))
                    newOrMap[newOr] = min(newOrMap[newOr], len + 1);
                else
                    newOrMap[newOr] = len + 1;
            }

            int maxOr = 0;
            for (auto& [orVal, len] : newOrMap) {
                maxOr = max(maxOr, orVal);
            }

            res[i] = newOrMap[maxOr];
            orMap = move(newOrMap);
        }

        return res;
    }
};