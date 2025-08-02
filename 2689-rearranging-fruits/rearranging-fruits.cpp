class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
    unordered_map<int, int> freq1, freq2, totalFreq;
    for (int f : basket1) freq1[f]++;
    for (int f : basket2) freq2[f]++;

    for (auto& [fruit, count] : freq1) totalFreq[fruit] += count;
    for (auto& [fruit, count] : freq2) totalFreq[fruit] += count;

    for (auto& [fruit, count] : totalFreq) {
        if (count % 2 != 0) return -1;
    }

    vector<int> extra1, extra2;
    for (auto& [fruit, _] : totalFreq) {
        int c1 = freq1[fruit];
        int c2 = freq2[fruit];
        if (c1 > c2) {
            for (int i = 0; i < (c1 - c2) / 2; ++i) extra1.push_back(fruit);
        } else if (c2 > c1) {
            for (int i = 0; i < (c2 - c1) / 2; ++i) extra2.push_back(fruit);
        }
    }

    if (extra1.size() != extra2.size()) return -1;

    sort(extra1.begin(), extra1.end());
    sort(extra2.rbegin(), extra2.rend());

    int minVal = min(*min_element(basket1.begin(), basket1.end()), 
                     *min_element(basket2.begin(), basket2.end()));

    long long cost = 0;
    for (size_t i = 0; i < extra1.size(); ++i) {
        int a = extra1[i], b = extra2[i];
        cost += min(min(a, b), 2 * minVal);
    }

    return cost;
    }
};