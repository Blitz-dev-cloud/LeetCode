class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> fruitsCount;
        int left = 0, maxFruits = 0;
        
        for( int right = 0 ; right < fruits.size() ; right++ ) {
            fruitsCount[fruits[right]]++;

            while(fruitsCount.size() > 2) {
                fruitsCount[fruits[left]]--;
                if(fruitsCount[fruits[left]] == 0) fruitsCount.erase(fruits[left]);
                left++;
            }

            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};