#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  int INF = INT_MAX;

  int bfsFromEmptyRoom(int i, int j, vector<vector<int>>& rooms) {
    vector<vector<bool>> visited = vector<vector<bool>>(rooms.size(), vector<bool>(rooms[0].size()));
    queue<vector<int>> q; // i,j,steps
    q.push({i,j,0});
    while(!q.empty()) {
      int x = q.front()[0];
      int y = q.front()[1];
      int steps = q.front()[2];
      q.pop();
      // validity
      if(!(x >= 0 && x < rooms.size() && y >= 0 && y < rooms[0].size())) continue;
      if(visited[x][y] == true) continue;
      visited[x][y] = true;
      if(rooms[x][y] == 0) return steps; // gate
      if(rooms[x][y] == -1) continue; // wall

      // any other number, we are at new empty room, so bfs from here
      q.push({x+1,y,steps+1});
      q.push({x-1,y,steps+1});
      q.push({x,y+1,steps+1});
      q.push({x,y-1,steps+1});
    }

    return INF; // couldn't reach a gate
  }

  void bfsFromGate(int i, int j, vector<vector<int>>& rooms) {
    vector<vector<bool>> visited = vector<vector<bool>>(rooms.size(), vector<bool>(rooms[0].size()));
    queue<vector<int>> q; // i,j,steps
    q.push({i,j,0});
    while(!q.empty()) {
      int x = q.front()[0];
      int y = q.front()[1];
      int steps = q.front()[2];
      q.pop();

      auto isValidCell = [&]() -> bool {
        return x >= 0 && x < rooms.size() && y >= 0 && y < rooms[0].size();
      };

      // validity of cell to visit
      if(!isValidCell()) continue;
      if(rooms[x][y] == -1) continue; // wall
      if(visited[x][y] == true) continue;
      visited[x][y] = true;

      // empty room || gate
      // >= so we run bfs from gate when we start bfs from gate
      if(rooms[x][y] >= steps) {
        rooms[x][y] = steps;
        // run bfs from here, we can improve!
        q.push({x+1,y,steps+1});
        q.push({x-1,y,steps+1});
        q.push({x,y+1,steps+1});
        q.push({x,y-1,steps+1});
      }
    }
  }

  void oldWallsAndGates(vector<vector<int>>& rooms) {
    queue<vector<int>> q; // i,j,steps

    // Adding all gates to queue
    for(int i = 0; i < rooms.size(); i++) {
      for(int j = 0; j < rooms[i].size(); j++) {
        if(rooms[i][j] == 0) q.push({i,j,0});
      }
    }

    // bfs
    while(!q.empty()) {
      int x = q.front()[0];
      int y = q.front()[1];
      int steps = q.front()[2];
      q.pop();

      auto isValidCell = [&]() -> bool {
        return x >= 0 && x < rooms.size() && y >= 0 && y < rooms[0].size();
      };

      // validity of cell to visit
      if(!isValidCell()) continue;
      if(rooms[x][y] == -1) continue; // wall

      // empty room || gate only when it's the bfs start point!
      if(rooms[x][y] >= steps) {
        rooms[x][y] = steps;
        q.push({x+1,y,steps+1});
        q.push({x-1,y,steps+1});
        q.push({x,y+1,steps+1});
        q.push({x,y-1,steps+1});
      }
    }
  }

  void wallsAndGates(vector<vector<int>>& rooms) {
    queue<vector<int>> q; // i,j,steps

    // Adding all gates to queue
    for(int i = 0; i < rooms.size(); i++) {
      for(int j = 0; j < rooms[i].size(); j++) {
        if(rooms[i][j] == 0) q.push({i,j,0});
      }
    }

    // valid coordinate && not a wall
    auto isValidCell = [&](int x, int y) -> bool {
      return (x >= 0 && x < rooms.size() && y >= 0 && y < rooms[0].size()) && (rooms[x][y] != -1);
    };

    // bfs
    while(!q.empty()) {
      int x = q.front()[0];
      int y = q.front()[1];
      int steps = q.front()[2];
      q.pop();

      // empty room || bfs start point (== gate)
      if(rooms[x][y] == INF || steps == 0) {
        rooms[x][y] = steps;
        // only push valid cells
        if(isValidCell(x+1,y)) q.push({x+1,y,steps+1});
        if(isValidCell(x-1,y)) q.push({x-1,y,steps+1});
        if(isValidCell(x,y+1)) q.push({x,y+1,steps+1});
        if(isValidCell(x,y-1)) q.push({x,y-1,steps+1});
      }
    }
  }
};