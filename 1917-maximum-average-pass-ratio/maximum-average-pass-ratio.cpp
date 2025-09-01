class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int p, int t) {
            return (double)(p + 1) / (t + 1) - (double)p / t;
        };

        priority_queue<pair<double, pair<int,int>>> pq;
        for (auto &c : classes) {
            int p = c[0], t = c[1];
            pq.push({gain(p, t), {p, t}});
        }

        while (extraStudents--) {
            auto [g, pt] = pq.top(); pq.pop();
            int p = pt.first, t = pt.second;
            p++; t++;
            pq.push({gain(p, t), {p, t}});
        }

        double total = 0.0;
        while (!pq.empty()) {
            auto [g, pt] = pq.top(); pq.pop();
            int p = pt.first, t = pt.second;
            total += (double)p / t;
        }

        return total / classes.size();
    }
};