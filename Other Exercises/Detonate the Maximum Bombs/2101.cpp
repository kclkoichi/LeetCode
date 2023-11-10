#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
  double distance(vector<int> a, vector<int> b) {
    return sqrt((pow((a[0] - b[0]), 2) + pow((a[1] - b[1]), 2)));
  }

  int maximumDetonation(vector<vector<int>>& bombs) {
    unordered_map<int, vector<int>> AL;

    for(int i = 0; i < bombs.size(); i++) {
      vector<int> bomb1 = bombs[i];
      for(int j = 0; j < bombs.size(); j++) {
        if(i == j) continue;
        vector<int> bomb2 = bombs[j];
        if(distance(bomb1, bomb2) <= bomb1[2]) {
          AL[i].push_back(j); // bomb1 detonation reaches bomb2
        }
      }
    }

    // dfs
    int maxCount = 0;
    for(int i = 0; i < bombs.size(); i++) {
      int count = 0;
      vector<bool> visited(bombs.size(), false);
      stack<int> s;
      s.push(i);
      while(!s.empty()) {
        int bomb = s.top();
        s.pop();
        if(visited[bomb] == true) continue;
        visited[bomb] = true;
        count++;
        maxCount = count > maxCount ? count : maxCount;
        for(int reachable: AL[bomb]) {
          s.push(reachable);
        }
      }
    }

    return maxCount;
  }
};