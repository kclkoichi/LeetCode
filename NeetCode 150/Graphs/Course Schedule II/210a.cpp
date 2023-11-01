#include <vector>
using namespace std;

class Solution {
public:
  void dfs(int cur, vector<vector<int>>& AL, vector<int>& res, bool& cycle, vector<int>& visited, vector<int>& finishedVisited) {
    if(cycle || finishedVisited[cur]) return;
    if(visited[cur] && !finishedVisited[cur]) {
      cycle = true;
      return;
    }

    visited[cur] = true;
    for(int neighbour: AL[cur]) {
      dfs(neighbour, AL, res, cycle, visited, finishedVisited);
    }

    finishedVisited[cur] = true;
    res.push_back(cur);
  }

  // topological sort
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> AL(numCourses, vector<int>());
    for(auto pair: prerequisites) {
      int course = pair[0];
      int prerequisite = pair[1];
      AL[course].push_back(prerequisite);
    }

    vector<int> visited(numCourses);
    vector<int> finishedVisited(numCourses);

    vector<int> res;
    bool cycle = false;
    for(int i = 0; i < numCourses; i++) {
      dfs(i, AL, res, cycle, visited, finishedVisited);
    }
    return cycle ? vector<int>() : res;
  }
};