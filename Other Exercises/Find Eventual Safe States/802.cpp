#include <vector>
using namespace std;

class Solution {
public:
  bool canReachTerminal(int i, vector<vector<int>>& graph, vector<bool>& canReach, vector<bool>& visited) {
    if(canReach[i]) return true;
    if(visited[i]) return false; // cannot reach
    visited[i] = true;
    for(int neighbour: graph[i]) {
      if(!canReachTerminal(neighbour, graph, canReach, visited)) return false;
    }
    canReach[i] = true;
    return true;
  }

  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> canReach(n);
    vector<bool> visited(n);
    for(int i = 0; i < n; i++) {
      canReachTerminal(i, graph, canReach, visited);
    }
    vector<int> res;
    for(int i = 0; i < n; i++) if(canReach[i]) res.push_back(i);
    return res;
  }
};