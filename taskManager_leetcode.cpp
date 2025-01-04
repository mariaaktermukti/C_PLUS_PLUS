#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

class TaskManager {
private:
    struct Task {
        int userId;
        int priority;
    };

    unordered_map<int, Task> taskMap;
    set<pair<int, int>> prioritySet;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            add(userId, taskId, priority);
        }
    }

    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority};
        prioritySet.insert({-priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        auto it = taskMap.find(taskId);
        if (it != taskMap.end()) {
            int oldPriority = it->second.priority;
            prioritySet.erase({-oldPriority, taskId});
            it->second.priority = newPriority;
            prioritySet.insert({-newPriority, taskId});
        }
    }

    void rmv(int taskId) {
        auto it = taskMap.find(taskId);
        if (it != taskMap.end()) {
            int priority = it->second.priority;
            prioritySet.erase({-priority, taskId});
            taskMap.erase(it);
        }
    }

    int execTop() {
        if (prioritySet.empty()) {
            return -1;
        }
        auto top = *prioritySet.begin();
        int taskId = top.second;
        int userId = taskMap[taskId].userId;
        rmv(taskId); 
        return userId;
    }
};

int main() {
    vector<vector<int>> tasks = {{1, 101, 10}, {2, 102, 20}, {3, 103, 15}};
    TaskManager taskManager(tasks);

    taskManager.add(4, 104, 5);
    taskManager.edit(102, 8);
    cout << taskManager.execTop() << endl; 
    taskManager.rmv(101);
    taskManager.add(5, 105, 15);
    cout << taskManager.execTop() << endl; 

    return 0;
}
