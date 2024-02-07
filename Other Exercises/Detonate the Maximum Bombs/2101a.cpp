#include <vector>
using namespace std;

class Solution {
public:
  bool canReach(vector<int> bomb1, vector<int> bomb2) {
    return (double) bomb1[2] >= sqrt(pow(abs(bomb1[0] - bomb2[0]), 2) + pow(abs(bomb1[1] - bomb2[1]), 2));
  }

  int dfs(int i, vector<vector<int>>& AL, vector<bool>& vis) {
    if(vis[i]) return 0;
    vis[i] = true;
    int howManyFromNext = 0;
    for(int next: AL[i]) howManyFromNext += dfs(next, AL, vis);
    return 1 + howManyFromNext;
  }

  int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    vector<vector<int>> AL(n, vector<int>());
    for(int i = 0; i < bombs.size(); i++) {
      vector<int> exploded = bombs[i];
      for(int j = 0; j < bombs.size(); j++) {
        if(i == j) continue;
        vector<int> toExplode = bombs[j];
        if(canReach(exploded, toExplode)) {
          AL[i].push_back(j); // exploded can reach toExplode
        } 
      }
    }

    int maxExploded = 0;
    for(int i = 0; i < bombs.size(); i++) {
      vector<bool> vis(n);
      maxExploded = max(dfs(i, AL, vis), maxExploded);
    }
    return maxExploded;
  }
};