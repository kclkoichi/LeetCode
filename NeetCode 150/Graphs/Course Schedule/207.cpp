#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool dfs(int cur, vector<vector<int>>& graph, unordered_set<int>& vis) {
    vis.insert(cur);
    for(int neighbour : graph[cur]) {
      if(vis.find(neighbour) != vis.end()) return true; // cycle detected
      if(dfs(neighbour, graph, vis)) return true;
    }
    vis.erase(cur);
    return false; // no cycle
  }

  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph = vector<vector<int>>(2001, vector<int> {} );
    for(vector<int> pre : prerequisites) graph[pre[0]].push_back(pre[1]); // e.g 1->0 1 needs 0 to be completed first
    for(int i = 0; i <= 2000; i++) {
      unordered_set<int> vis;
      if(dfs(i, graph, vis)) return false;
    }
    return true;
  }
};