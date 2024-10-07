#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  int dfs(int i, vector<int>& howManyFrom, vector<bool>& visited, vector<vector<int>>& AL) {
    if(howManyFrom[i] != -9) return howManyFrom[i];
    if(visited[i]) return -1;
    visited[i] = true;
    int maxDist = 1;
    for(int neighbour: AL[i]) {
      int dist = dfs(neighbour, howManyFrom, visited, AL);
      if(dist == -1) return -1;
      maxDist = max(maxDist, 1 + dist); // 1 is itself
    }
    howManyFrom[i] = maxDist;
    return maxDist;
  }

  int minimumSemesters(int n, vector<vector<int>>& relations) {
    vector<vector<int>> AL(n+1, vector<int>());
    for(vector<int> relation: relations) AL[relation[0]].push_back(relation[1]);

    vector<int> howManyFrom(n+1, -9);
    vector<bool> visited(n+1, false);
    int maxDist = 0;
    for(int i = 1; i <= n; i++) {
      int dist = dfs(i, howManyFrom, visited, AL);
      if(dist == -1) return -1;
      maxDist = max(maxDist, dist);
    }
    return maxDist;
  }
};
