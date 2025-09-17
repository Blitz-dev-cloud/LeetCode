class FoodRatings {
public:
    unordered_map<string, pair<string,int>> foodMap;
    unordered_map<string, set<pair<int,string>>> cuisineMap;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodMap[foods[i]] = {cuisines[i], ratings[i]};
            cuisineMap[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodMap[food];
        cuisineMap[cuisine].erase({-oldRating, food});
        cuisineMap[cuisine].insert({-newRating, food});
        foodMap[food] = {cuisine, newRating};
    }
    
    string highestRated(string cuisine) {
        return cuisineMap[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */