class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();

        vector<unordered_set<int>> langSets(m);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                langSets[i].insert(lang);
            }
        }

        unordered_set<int> needFix;
        for (auto &f : friendships) {
            int u = f[0] - 1, v = f[1] - 1;
            bool canCommunicate = false;
            for (int lang : langSets[u]) {
                if (langSets[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                needFix.insert(u);
                needFix.insert(v);
            }
        }

        int res = INT_MAX;
        for (int lang = 1; lang <= n; lang++) {
            int count = 0;
            for (int user : needFix) {
                if (!langSets[user].count(lang)) {
                    count++;
                }
            }
            res = min(res, count);
        }

        return res;
    }
};