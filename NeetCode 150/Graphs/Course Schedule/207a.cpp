#include <vector>
using namespace std;

class Solution {
public:
  void dfs(int i, vector<bool>& finishedVisited, vector<bool>& visited, vector<vector<int>>& adjacencyList, bool& cycle) {
    if(finishedVisited[i]) return;
    // We are coming back somewhere, so cycle!!
    if(visited[i] && !finishedVisited[i]) {
      cycle = true;
      return;
    }

    visited[i] = true;
    for(int prerequisite: adjacencyList[i]) dfs(prerequisite, finishedVisited, visited, adjacencyList, cycle);
    finishedVisited[i] = true;
  }

  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<bool> finishedVisited = vector<bool>(numCourses);
    vector<bool> visited = vector<bool>(numCourses);

    vector<vector<int>> adjacencyList = vector<vector<int>>(numCourses, vector<int>());
    for(vector<int> prerequisite: prerequisites) {
      int course = prerequisite[0];
      int neededCourse = prerequisite[1];
      adjacencyList[course].push_back(neededCourse);
    }

    bool cycle = false;
    for(int i = 0; i < numCourses; i++) {
      dfs(i, finishedVisited, visited, adjacencyList, cycle);
      if(cycle) return false;
    }

    return true;
  }
};