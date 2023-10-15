#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  // Kahn's algorithm but ugly
  vector<int> oldFindOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjacencyList = vector<vector<int>>(numCourses, vector<int>());
    for(vector<int> dependency: prerequisites) {
      int course = dependency[0];
      int needed = dependency[1];
      adjacencyList[course].push_back(needed);
    }
    vector<int> res;
    bool finished = false;
    vector<bool> completed = vector<bool>(numCourses);
    while(!finished) {
      int count = 0;
      for(int i = 0; i < adjacencyList.size(); i++) {
        vector<int> neededCourses = adjacencyList[i];
        // means outdegree = 0
        if(neededCourses.size() == 0 && !completed[i]) {
          completed[i] = true;
          count++;
          res.push_back(i);
          // in AL, remove i from prerequisite of all courses
          for(int j = 0; j < adjacencyList.size(); j++) {
            for(auto it = adjacencyList[j].begin(); it != adjacencyList[j].end(); ++it) {
              if(*it == i) {
                auto del = it;
                --it;
                adjacencyList[j].erase(del);
              }
            }
          }
        }
      }
      if(count == 0) {
        for(int i = 0; i < completed.size(); i++) {
          if(completed[i] == false) return {};
        }
        finished = true;
      }
    }
    return res;
  }

  // Better Kahn's algorithm
  vector<int> findOrderKahn(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjacencyList = vector<vector<int>>(numCourses, vector<int>());
    vector<int> indegrees = vector<int>(numCourses);
    for(vector<int> dependency: prerequisites) {
      int course = dependency[0];
      int needs = dependency[1];
      adjacencyList[needs].push_back(course); // Reversed: We needed to take the needed course to take the course
      indegrees[course]++;
    }

    queue<int> q;
    for(int i = 0; i < numCourses; i++) if(indegrees[i] == 0) q.push(i); // push nodes with indegree 0
    if(q.empty()) return {}; // there is a cycle if there is no node with indegree 0

    vector<int> topoSort;
    while(!q.empty()) {
      int curNode = q.front();
      q.pop();
      topoSort.push_back(curNode);
      for(int next: adjacencyList[curNode]) {
        indegrees[next]--;
        if(indegrees[next] == 0) q.push(next);
      }
    }

    // Final check
    for(int i = 0; i < numCourses; i++) if(indegrees[i] > 0) return {}; // there is a cycle
    return topoSort;
  }

  void dfs(int i, vector<bool>& visited, vector<bool>& finishedVisited, vector<int>& topoSort, vector<vector<int>>& adjacencyList, bool& cycle) {
    if(finishedVisited[i]) return;
    if(visited[i] && !finishedVisited[i]) {
      cycle = true;
      return;
    }

    visited[i] = true;
    for(int neighbour: adjacencyList[i]) dfs(neighbour, visited, finishedVisited, topoSort, adjacencyList, cycle);
    finishedVisited[i] = true;
    topoSort.push_back(i);
  }

  // dfs
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjacencyList = vector<vector<int>>(numCourses, vector<int>());
    for(vector<int> dependency: prerequisites) {
      int course = dependency[0];
      int needed = dependency[1];
      adjacencyList[course].push_back(needed);
    }

    vector<int> topoSort;
    vector<bool> visited = vector<bool>(numCourses);
    vector<bool> finishedVisited = vector<bool>(numCourses);
    for(int i = 0; i < numCourses; i++) {
      bool cycle = false;
      dfs(i, visited, finishedVisited, topoSort, adjacencyList, cycle);
      if(cycle) return {};
    }
    return topoSort;
  }

};