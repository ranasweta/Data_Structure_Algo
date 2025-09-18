class TaskManager {
public:
    map<int, int> task_user;
    map<int, int> task_priority;
    set<pair<int, int>> task;
    // our primary key is task

    TaskManager(vector<vector<int>>& tasks) {
        for (auto i : tasks) {
            int userid = i[0];
            int taskid = i[1];
            int priority = i[2];
            task_priority[taskid] = priority;
            task_user[taskid] = userid;
            task.insert({priority,taskid});
        }
    }

    void add(int userId, int taskId, int priority) {
            task_priority[taskId] = priority;
            task_user[taskId] = userId;
            task.insert({priority,taskId});


    }

    void edit(int taskId, int newPriority) {
            int p=task_priority[taskId];
            task_priority[taskId] = newPriority;
            task.erase({p,taskId});
            task.insert({newPriority,taskId});


    }

    void rmv(int taskId) {
        int p=task_priority[taskId];
        task.erase({p,taskId});
        task_priority.erase(taskId);
        task_user.erase(taskId);
    }

    int execTop() {
        if(task.size()==0) return -1;
        int taskid= task.rbegin()->second;
        int userid= task_user[taskid];
        rmv(taskid);
        return userid;
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