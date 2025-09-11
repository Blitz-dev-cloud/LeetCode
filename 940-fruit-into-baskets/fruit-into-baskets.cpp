class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> counts;
        int left = 0, maxFruits = 0;

        for( int right = 0 ; right < fruits.size() ; right++ ) {
            counts[fruits[right]]++;

            while(counts.size() > 2) {
                counts[fruits[left]]--;
                if(counts[fruits[left]] == 0) counts.erase(fruits[left]);
                left++;
            }

            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};