#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Time: O(n^2 log n)
class Solution {
public:
  int maximumMinutes(vector<vector<int>>& grid) {
    // Make fire map
    queue<pair<int, pair<int, int>>> fireQ;
    for(int i = 0; i < grid.size(); i++) {
      for(int j = 0; j < grid[0].size(); j++) {
        if(grid[i][j] == 1) fireQ.push(make_pair(0, make_pair(i, j))); // time, <x,y>
      }
    }
    vector<vector<int>> fireMap(grid.size(), vector<int>(grid[0].size(), -1)); // -1 in firemap means fire cannot reach
    while(!fireQ.empty()) {
      int time = fireQ.front().first;
      int x = fireQ.front().second.first;
      int y = fireQ.front().second.second;
      fireQ.pop();
      
      if(x < 0 || x > grid.size() - 1 || y < 0 || y > grid[0].size() - 1) continue; // out of bounds
      if(fireMap[x][y] != -1) continue; // already reached
      if(grid[x][y] == 2) continue; // a wall

      // Set on fire
      fireMap[x][y] = time;
      fireQ.push(make_pair(time+1, make_pair(x-1, y)));
      fireQ.push(make_pair(time+1, make_pair(x+1, y)));
      fireQ.push(make_pair(time+1, make_pair(x, y-1)));
      fireQ.push(make_pair(time+1, make_pair(x, y+1)));
    }

    // Sort by ASC maxWaitTime, DESC currentTime
    auto cmp = [](vector<int> a, vector<int> b) {
      // Can add heuristic of x y closer to goal
      if(a[0] == b[0]) a[1] > b[1];
      return a[0] < b[0];
    };

    // BFS to solution
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> walkingQ;
    walkingQ.push({1000000000, 0, 0, 0}); // maxWaitTime, currentTime, x, y
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
    while(!walkingQ.empty()) {
      vector<int> tmp = walkingQ.top();
      int waitTime = walkingQ.top()[0];
      int curTime = walkingQ.top()[1];
      int x = walkingQ.top()[2];
      int y = walkingQ.top()[3];
      walkingQ.pop();

      if(x < 0 || x > grid.size() - 1 || y < 0 || y > grid[0].size() - 1) continue; // out of bounds
      if(grid[x][y] == 2) continue; // a wall
      if(visited[x][y]) continue;
      visited[x][y] = true;

      int maxWaitTimeIfHaveToMove = waitTime;

      // Fire can reach
      if(fireMap[x][y] != -1) maxWaitTimeIfHaveToMove = min(waitTime, fireMap[x][y] - curTime - 1);

      // Goal
      if(x == grid.size()-1 && y == grid[0].size()-1) {
        if(fireMap[x][y] != -1) {
          if(fireMap[x][y] == curTime) return 0;
          if(fireMap[x][y] < curTime) return -1;
        } else {
          return 1000000000; // If fire cannot reach goal, then it also cannot reach beginning
        }
        return min(waitTime, fireMap[x][y] - curTime); // because special case goal, we can wait till we burn
      }

      if(maxWaitTimeIfHaveToMove < 0) continue; // We died

      walkingQ.push({maxWaitTimeIfHaveToMove, curTime+1, x-1, y});
      walkingQ.push({maxWaitTimeIfHaveToMove, curTime+1, x, y-1});
      walkingQ.push({maxWaitTimeIfHaveToMove, curTime+1, x+1, y});
      walkingQ.push({maxWaitTimeIfHaveToMove, curTime+1, x, y+1});
    }

    return -1; // We could not reach the goal
  }
};
