#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Time complexity: O(N log N) with N number of tasks
// Space complexity: O(N)
class Solution {
public:
  // task = enqueue Time AND processing time 
  vector<int> getOrder(vector<vector<int>>& tasks) {
    for(int i = 0; i < tasks.size(); i++) {
      tasks[i].push_back(i); // remember id of task
    }

    // sort in ASC enqueue time
    auto cmpTask = [](vector<int> task1, vector<int> task2) {
      return task1[0] < task2[0];
    };
    sort(tasks.begin(), tasks.end());

    // Sorted in ASC processing time, ASC task id
    auto cmp = [](vector<int> task1, vector<int> task2) {
      // > because max heap originally
      if(task1[1] == task2[1]) return task1[2] > task2[2];
      return task1[1] > task2[1];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> availableTasks;

    int taskIndex = 0;
    vector<int> res;
    long long time = 1;
    while(res.size() != tasks.size()) {
      // Enqueue all tasks with current time >= enqueue time
      while(taskIndex < tasks.size() && time >= tasks[taskIndex][0]) {
        availableTasks.push(tasks[taskIndex]);
        taskIndex++;
      }
      // If there is a task
      if(availableTasks.size() > 0) {
        // Take shortest completion time, smallest id
        vector<int> task = availableTasks.top();
        availableTasks.pop();
        int taskId = task[2];
        int completionTime = task[1];
        res.push_back(taskId);
        // Skip time after completion of task
        time += completionTime;
      } else {
        // If no task, skip to time of next enqueue
        time = tasks[taskIndex][0];
        // the while loop is gonna enqueue the task
      }
    }

    return res;
  }
};

// MLE
class Solution {
public:
  // task = enqueue Time AND processing time 
  vector<int> getOrder(vector<vector<int>>& tasks) {
    unordered_map<int, vector<int>> enqueueTimeToTaskId;
    for(int i = 0; i < tasks.size(); i++) {
      tasks[i].push_back(i); // remember id of task
      vector<int> task = tasks[i];
      enqueueTimeToTaskId[task[0]].push_back(i); // i is the id of the task
    }

    // Sorted in ASC processing time, ASC task id
    auto cmp = [](vector<int> task1, vector<int> task2) {
      // > because max heap originally
      if(task1[1] == task2[1]) return task1[2] > task2[2];
      return task1[1] > task2[1];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> availableTasks;

    int remainingTimeToProcess = 0; // of current task
    vector<int> res;
    for(int time = 1; res.size() != tasks.size(); time++) {
      // Add to availble tasks
      for(int taskId: enqueueTimeToTaskId[time]) {
        availableTasks.push(tasks[taskId]);
      }
      if(remainingTimeToProcess > 0) {
        // processing a task currently
        remainingTimeToProcess--;
      }
      if(remainingTimeToProcess == 0) {
        // can take a new task
        if(availableTasks.size() > 0) {
          vector<int> task = availableTasks.top();
          availableTasks.pop();
          remainingTimeToProcess = task[1]; // process time of the task
          res.push_back(task[2]); // push id of task
        }
      }
    }

    return res;
  }
};

// TLE
// Time: O(T log N) with T is time at which we process the last task (so very big...)
class Solution {
public:
  // task = enqueue Time AND processing time 
  vector<int> getOrder(vector<vector<int>>& tasks) {
    for(int i = 0; i < tasks.size(); i++) {
      tasks[i].push_back(i); // remember id of task
    }

    // sort in ASC enqueue time
    auto cmpTask = [](vector<int> task1, vector<int> task2) {
      return task1[0] < task2[0];
    };
    sort(tasks.begin(), tasks.end());

    // Sorted in ASC processing time, ASC task id
    auto cmp = [](vector<int> task1, vector<int> task2) {
      // > because max heap originally
      if(task1[1] == task2[1]) return task1[2] > task2[2];
      return task1[1] > task2[1];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> availableTasks;

    int remainingTimeToProcess = 0; // of current task
    int taskIndex = 0;
    vector<int> res;
    for(int time = 1; res.size() != tasks.size(); time++) {
      // Add to availble tasks. While because might have tasks with same enqueue time
      while(taskIndex < tasks.size() && time == tasks[taskIndex][0]) {
        availableTasks.push(tasks[taskIndex]); // enqueue because it's enqueue time
        taskIndex++;
      }
      if(remainingTimeToProcess > 0) {
        // processing a task currently
        remainingTimeToProcess--;
      }
      if(remainingTimeToProcess == 0) {
        // can take a new task
        if(availableTasks.size() > 0) {
          vector<int> task = availableTasks.top();
          availableTasks.pop();
          remainingTimeToProcess = task[1]; // process time of the task
          res.push_back(task[2]); // push id of task
        }
      }
    }

    return res;
  }
};
