class Router {
int memoryLimit;
    queue<tuple<int,int,int>> q;
    unordered_set<string> seen;
    unordered_map<int, vector<int>> destMap;
    unordered_map<int, int> frontIndex;

    string makeKey(int s, int d, int t) {
        return to_string(s) + "#" + to_string(d) + "#" + to_string(t);
    }

public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);
        if (seen.count(key)) return false;
        if ((int)q.size() == memoryLimit) {
            auto [os, od, ot] = q.front();
            q.pop();
            seen.erase(makeKey(os, od, ot));
            // lazy deletion: just advance pointer
            if (frontIndex.count(od) == 0) frontIndex[od] = 0;
            auto &vec = destMap[od];
            int idx = frontIndex[od];
            if (idx < (int)vec.size() && vec[idx] == ot) frontIndex[od]++;
        }
        q.push({source, destination, timestamp});
        seen.insert(key);
        destMap[destination].push_back(timestamp);
        if (frontIndex.count(destination) == 0) frontIndex[destination] = 0;
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto [s, d, t] = q.front();
        q.pop();
        seen.erase(makeKey(s, d, t));
        if (frontIndex.count(d) == 0) frontIndex[d] = 0;
        auto &vec = destMap[d];
        int idx = frontIndex[d];
        if (idx < (int)vec.size() && vec[idx] == t) frontIndex[d]++;
        return {s, d, t};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &vec = destMap[destination];
        if (frontIndex.count(destination) == 0) return 0;
        int startIdx = frontIndex[destination];
        if (startIdx >= (int)vec.size()) return 0;
        auto l = lower_bound(vec.begin() + startIdx, vec.end(), startTime);
        auto r = upper_bound(vec.begin() + startIdx, vec.end(), endTime);
        return r - l;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */