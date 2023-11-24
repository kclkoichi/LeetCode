#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Time: O(E + V^2) 
// Space: O(2E) = O(E)
class Solution {
public:
  vector<unordered_set<int>> AL;

  int connected(int a, int b) {
    if(AL[a].find(b) != AL[a].end()) return 1; // connected
    return 0; // not connected
  }

  int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    // time: O(E)
    AL = vector<unordered_set<int>>(n);
    for(vector<int> road: roads) {
      AL[road[0]].insert(road[1]);
      AL[road[1]].insert(road[0]);
    }

    int maxNR = 0;
    // time: O(V^2)
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
        maxNR = max(maxNR, (int) (AL[i].size() + AL[j].size() - connected(i,j)));
      }
    }
    return maxNR;
  }
};
