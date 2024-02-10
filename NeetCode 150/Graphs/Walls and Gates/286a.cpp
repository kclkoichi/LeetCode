#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    queue<pair<pair<int, int>, int>> q; // <x,y>, distance
    for(int i = 0; i < rooms.size(); i++) {
      for(int j = 0; j < rooms[0].size(); j++) {
        if(rooms[i][j] == 0) q.push(make_pair(make_pair(i,j), 0));
      }
    }
    while(!q.empty()) {
      int x = q.front().first.first;
      int y = q.front().first.second;
      int distance = q.front().second;
      q.pop();
      if(x < 0 || x >= rooms.size() || y < 0 || y >= rooms[0].size()) continue;
      if(rooms[x][y] == -1) continue;
      if(distance > 0) {
        if(rooms[x][y] == 0) continue; // We don't want to go back to gate
        if(rooms[x][y] < 2147483647) continue; // We already came here earlier
      }
      rooms[x][y] = distance;
      q.push(make_pair(make_pair(x-1, y), distance+1));
      q.push(make_pair(make_pair(x, y-1), distance+1));
      q.push(make_pair(make_pair(x+1, y), distance+1));
      q.push(make_pair(make_pair(x, y+1), distance+1));
    }
  }
};