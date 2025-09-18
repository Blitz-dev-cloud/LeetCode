class TaskManager {
private:
    struct Task {
        int priority;
        int taskId;
        int userId;
    };

    struct Compare {
        bool operator()(const Task &a, const Task &b) const {
            if (a.priority == b.priority)
                return a.taskId < b.taskId;
            return a.priority < b.priority;
        }
    };

    priority_queue<Task, vector<Task>, Compare> pq;
    unordered_map<int, pair<int,int>> taskMap;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            taskMap[taskId] = {userId, priority};
            pq.push({priority, taskId, userId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority};
        pq.push({priority, taskId, userId});
    }
    
    void edit(int taskId, int newPriority) {
        auto [userId, oldPriority] = taskMap[taskId];
        taskMap[taskId] = {userId, newPriority};
        pq.push({newPriority, taskId, userId});
    }
    
    void rmv(int taskId) {
        taskMap.erase(taskId);
    }
    
    int execTop() {
        while (!pq.empty()) {
            Task top = pq.top();
            pq.pop();
            if (taskMap.find(top.taskId) != taskMap.end() && taskMap[top.taskId].second == top.priority) {
                int userId = taskMap[top.taskId].first;
                taskMap.erase(top.taskId);
                return userId;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */