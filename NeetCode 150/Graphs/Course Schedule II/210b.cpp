#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
  void dfs(int i, vector<int>& sorted, vector<bool>& seen, vector<bool>& visited, vector<vector<int>>& AL, bool& cycle) {
    if(visited[i]) return;
    if(seen[i]) {
      cycle = true;
      return;
    }

    seen[i] = true;
    for(int neighbour: AL[i]) dfs(neighbour, sorted, seen, visited, AL, cycle);
    visited[i] = true;
    sorted.push_back(i);
  }

  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> AL(numCourses, vector<int>());
    for(vector<int> prereq: prerequisites) AL[prereq[0]].push_back(prereq[1]);

    // topological sort
    vector<int> sorted;
    vector<bool> seen(numCourses, false);
    vector<bool> visited(numCourses, false);
    bool cycle = false;
    for(int i = 0; i < numCourses; i++) {
      if(!visited[i]) dfs(i, sorted, seen, visited, AL, cycle);
      if(cycle) return {};
    }
    return sorted;
  }
};
