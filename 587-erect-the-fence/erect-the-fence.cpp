class Solution {
    //blitz
public:
    int orientation(const vector<int> &p, const vector<int> &q, const vector<int> &r) {
        long long val = (long long)(q[1] - p[1]) * (r[0] - q[0]) - 
                         (long long)(q[0] - p[0]) * (r[1] - q[1]);
        if (val == 0) return 0;
        return (val > 0) ? 1 : 2;
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n <= 3) return trees;
        
        int leftmost = 0;
        for (int i = 1; i < n; i++) {
            if (trees[i][0] < trees[leftmost][0] || 
                (trees[i][0] == trees[leftmost][0] && trees[i][1] < trees[leftmost][1])) {
                leftmost = i;
            }
        }
        
        vector<bool> visited(n, false);
        int p = leftmost;
        vector<vector<int>> result;
        
        do {
            int q = (p + 1) % n;
            for (int i = 0; i < n; i++) {
                if (orientation(trees[p], trees[q], trees[i]) == 2) {
                    q = i;
                }
            }
            
            for (int i = 0; i < n; i++) {
                if (visited[i]) continue;
                
                if (i != p && i != q && orientation(trees[p], trees[i], trees[q]) == 0) {
                    bool isBetween = true;
                    if ((trees[i][0] < min(trees[p][0], trees[q][0])) || 
                        (trees[i][0] > max(trees[p][0], trees[q][0]))) {
                        isBetween = false;
                    }
                    if ((trees[i][1] < min(trees[p][1], trees[q][1])) || 
                        (trees[i][1] > max(trees[p][1], trees[q][1]))) {
                        isBetween = false;
                    }
                    
                    if (isBetween) {
                        if (!visited[i]) {
                            result.push_back(trees[i]);
                            visited[i] = true;
                        }
                    }
                }
            }
            
            if (!visited[q]) {
                result.push_back(trees[q]);
                visited[q] = true;
            }
            
            p = q;
        } while (p != leftmost);
        
        return result;
    }
};