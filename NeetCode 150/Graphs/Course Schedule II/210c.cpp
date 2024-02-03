#include <vector>
using namespace std;

class Solution {
public:
  void dfs(int i, bool& cycle, vector<bool>& visited, vector<bool>& finishedVisited, vector<vector<int>>& AL, vector<int>& res) {
    if(finishedVisited[i]) return;
    if(visited[i]) {
      cycle = true;
      return;
    }
    visited[i] = true;
    for(int neighbour: AL[i]) {
      dfs(neighbour, cycle, visited, finishedVisited, AL, res);
      if(cycle) return;
    }
    finishedVisited[i] = true;
    res.push_back(i);
  }

  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> res;
    vector<vector<int>> AL(numCourses);
    for(vector<int> prereq: prerequisites) AL[prereq[0]].push_back(prereq[1]);

    bool cycle = false;
    vector<bool> visited(numCourses);
    vector<bool> finishedVisited(numCourses);
    for(int i = 0; i < numCourses; i++) {
      dfs(i, cycle, visited, finishedVisited, AL, res);
      if(cycle) return {};
    }

    return res;
  }
};