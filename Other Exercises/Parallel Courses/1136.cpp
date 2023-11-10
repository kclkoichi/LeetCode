#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
  // Assume no cycle
  void dfsMaxDepth(int node, int depth, int& maxDepth, vector<vector<int>>& AL) {
    maxDepth = max(maxDepth, depth);
    for(int neighbour: AL[node]) {
      dfsMaxDepth(neighbour, depth+1, maxDepth, AL);
    }
  }

  void dfsCycle(int node, bool& cycle, vector<bool>& visited, vector<bool>& finishedVisited, vector<vector<int>>& AL) {
    if(finishedVisited[node]) return;
    if(visited[node] && !finishedVisited[node]) {
      // cycle
      cycle = true;
      return;
    }
    visited[node] = true;
    for(int neighbour: AL[node]) {
      dfsCycle(neighbour, cycle, visited, finishedVisited, AL);
    }
    finishedVisited[node] = true;
  }

  int minimumSemesters(int n, vector<vector<int>>& relations) {
    vector<vector<int>> AL(n+1);
    for(vector<int> relation: relations) {
      int prereq = relation[0];
      int course = relation[1];
      AL[prereq].push_back(course);
    }

    bool cycle = false;
    vector<bool> visited(n+1, false);
    vector<bool> finishedVisited(n+1, false);
    for(int i = 1; i <= n; i++) {
      dfsCycle(i, cycle, visited, finishedVisited, AL);
    }
    if(cycle) return -1;

    int maxDepth = 0;
    for(int i = 1; i <= n; i++) {
      dfsMaxDepth(i, 1, maxDepth, AL);
    }
    return maxDepth;
  }
};

class Solution {
public:
  // Kahn's algorithm
  int minimumSemesters(int n, vector<vector<int>>& relations) {
    vector<vector<int>> AL(n+1);
    vector<int> indegrees(n+1);
    for(vector<int> relation: relations) {
      int prereq = relation[0];
      int course = relation[1];
      AL[prereq].push_back(course);
      indegrees[course]++;
    }

    queue<int> canTake;
    for(int i = 1; i <= n; i++) {
      if(indegrees[i] == 0) canTake.push(i);
    }

    int remaining = n;
    int count = 0;
    while(true) {
      queue<int> next;
      while(!canTake.empty()) {
        int node = canTake.front();
        canTake.pop();

        // Delete all edge from node
        for(int neighbour: AL[node]) {
          indegrees[neighbour]--;
          if(indegrees[neighbour] == 0) next.push(neighbour);
        }
        AL[node] = {};

        // Remove this node
        remaining--;
      }
      canTake = next;
      count++; // 1 semester happened, and we took every takeable course
      if(canTake.empty()) break; // there is nothing more visitable
    }

    return remaining == 0 ? count : -1; // there is a cycle if there are nodes left to visit
  }
};