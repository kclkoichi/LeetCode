#include <vector>
using namespace std;

class Solution {
public:
  void dfs(int i, vector<bool>& visited, vector<vector<int>>& AL) {
    if(visited[i]) return;
    visited[i] = true;
    for(int neighbour: AL[i]) dfs(neighbour, visited, AL);
  }

  int countComponents(int n, vector<vector<int>>& edges) {
    vector<bool> visited(n);
    vector<vector<int>> AL(n, vector<int>());
    for(auto edge: edges) {
      AL[edge[0]].push_back(edge[1]);
      AL[edge[1]].push_back(edge[0]);
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
      if(!visited[i]) {
        count++;
        dfs(i, visited, AL);
      }
    }
    return count;
  }
};