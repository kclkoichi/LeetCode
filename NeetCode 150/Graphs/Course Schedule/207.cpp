#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool dfs(int cur, vector<vector<int>>& graph, unordered_set<int>& vis, unordered_set<int>& completed) {
    vis.insert(cur);
    for(int neighbour : graph[cur]) {
      if(completed.find(neighbour) != completed.end()) continue; // We already completed that course
      if(vis.find(neighbour) != vis.end()) return true; // cycle detected
      if(dfs(neighbour, graph, vis, completed)) return true;
    }
    completed.insert(cur);
    return false; // no cycle
  }

  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph = vector<vector<int>>(numCourses, vector<int> {} );
    for(vector<int> pre : prerequisites) graph[pre[0]].push_back(pre[1]); // e.g 1->0 1 needs 0 to be completed first
    unordered_set<int> completed;
    for(int i = 0; i < numCourses; i++) {
      unordered_set<int> vis;
      if(completed.find(i) != completed.end()) continue; // We already completed it
      if(dfs(i, graph, vis, completed)) return false;
    }
    return true;
  }
};