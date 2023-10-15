#include <vector>
using namespace std;

class Solution {
public:
  void dfs(int i, vector<vector<int>>& adjacencyList, vector<bool>& visited) {
    if(visited[i] == true) return;
    visited[i] = true;
    vector<int> neighbours = adjacencyList[i];
    for(int neighbour: neighbours) dfs(neighbour, adjacencyList, visited);
  }

  int countComponents(int n, vector<vector<int>>& edges) {
    int count = 0;
    vector<vector<int>> adjacencyList = vector<vector<int>>(n, vector<int>());
    for(vector<int> edge : edges) {
      adjacencyList[edge[0]].push_back(edge[1]);
      adjacencyList[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited = vector<bool>(n);
    for(int i = 0; i < n; i++) {
      if(!visited[i]) {
        count++;
        dfs(i, adjacencyList, visited);
      }
    }
    return count;
  }
};