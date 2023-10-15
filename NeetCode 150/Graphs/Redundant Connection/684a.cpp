#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  void dfs(int i, int prev, unordered_set<int>& visited, unordered_map<int, vector<int>>& adjacencyList, bool& cycle) {
    visited.insert(i);
    for(int neighbour: adjacencyList[i]) {
      // neighbour already visited
      if(visited.find(neighbour) != visited.end()) {
        if(neighbour == prev) {
          // skip, because it's fake cycle with where we come from
        } else {
          // cycle
          cycle = true;
          return; 
        }
      } else {
        dfs(neighbour, i, visited, adjacencyList, cycle);
      }
    }
  }

  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> adjacencyList;
    for(vector<int> edge: edges) {
      adjacencyList[edge[0]].push_back(edge[1]);
      adjacencyList[edge[1]].push_back(edge[0]);
      bool cycle = false;
      unordered_set<int> visited;
      dfs(edge[0], -1, visited, adjacencyList, cycle); // -1 for prev as there is no prev
      if(cycle) return edge;
    }
    return {-1, -1}; // as the given set of edges always have a cycle, this should never happen
  }
};