#include <vector>
using namespace std;

// Depth-First Search: Check for Cycles + Find Longest Path
// O(V+E)
class Solution {
public:
  int dfs(int i, vector<int>& lengths, vector<bool>& seen, bool& cycle, vector<vector<int>>& AL) {
    if(lengths[i] != -1) return lengths[i];
    if(seen[i]) {
      cycle = true;
      return -1;
    }
    seen[i] = true;

    int length = 0;
    for(int neighbour: AL[i]) {
      length = max(length, dfs(neighbour, lengths, seen, cycle, AL));
    }
    
    lengths[i] = length + 1;
    return lengths[i];
  }

  int minimumSemesters(int n, vector<vector<int>>& relations) {
    vector<vector<int>> AL(n, vector<int>());
    for(vector<int> relation: relations) AL[relation[0]-1].push_back(relation[1]-1); // 0-index based

    vector<int> lengths(n, -1);
    vector<bool> seen(n);
    bool cycle = false;
    int maxL = 0;
    for(int i = 0; i < n; i++) {
      maxL = max(maxL, dfs(i, lengths, seen, cycle, AL));
      if(cycle) return -1;
    }
    return maxL;
  }
};
