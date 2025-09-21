class MovieRentingSystem {
unordered_map<int, unordered_map<int,int>> price;
    unordered_map<int, set<pair<int,int>>> available;
    set<tuple<int,int,int>> rented;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], cost = e[2];
            price[shop][movie] = cost;
            available[movie].insert({cost, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        if (!available.count(movie)) return res;
        auto &s = available[movie];
        int cnt = 0;
        for (auto it = s.begin(); it != s.end() && cnt < 5; ++it, ++cnt) {
            res.push_back(it->second);
        }
        return res;
    }

    void rent(int shop, int movie) {
        int cost = price[shop][movie];
        available[movie].erase({cost, shop});
        rented.insert({cost, shop, movie});
    }

    void drop(int shop, int movie) {
        int cost = price[shop][movie];
        rented.erase({cost, shop, movie});
        available[movie].insert({cost, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt = 0;
        for (auto it = rented.begin(); it != rented.end() && cnt < 5; ++it, ++cnt) {
            auto [cost, shop, movie] = *it;
            res.push_back({shop, movie});
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */