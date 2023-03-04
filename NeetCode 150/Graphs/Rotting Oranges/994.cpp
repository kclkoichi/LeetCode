#include <vector>
#include <math.h>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    vector<vector<int>> time = vector(grid.size(), vector(grid[0].size(), INT_MAX));
    for(int i = 0; i < grid.size(); i++) {
      for(int j = 0; j < grid[0].size(); j++) {
        if(grid[i][j] == 2) {
          vector<vector<bool>> vis = vector(grid.size(), vector(grid[0].size(), false));
          queue<vector<int>> q;
          q.push(vector<int> { i-1, j, 1 });
          q.push(vector<int> { i, j-1, 1 });
          q.push(vector<int> { i+1, j, 1 });
          q.push(vector<int> { i, j+1, 1 });
          // BFS
          while(!q.empty()) {
            int row = q.front()[0];
            int col = q.front()[1];
            int curTime = q.front()[2];
            q.pop();
            if(row < 0 || col < 0 || row > grid.size() - 1 || col > grid[0].size() - 1) continue; 
            if(grid[row][col] == 0 || grid[row][col] == 2) continue; // no orange or already rotten
            if(curTime < time[row][col]) time[row][col] = curTime;
            if(!vis[row][col]) {
              vis[row][col] = true;
              q.push(vector<int> { row-1, col, curTime+1 });
              q.push(vector<int> { row, col-1, curTime+1 });
              q.push(vector<int> { row+1, col, curTime+1 });
              q.push(vector<int> { row, col+1, curTime+1 });
            }
          }
        }
      }
    }
    for(int i = 0; i < grid.size(); i++) {
      for(int j = 0; j < grid[0].size(); j++) {
        cout << time[i][j] << " ";
      }
      cout << "\n";
    }

    int maxTime = 0;
    for(int i = 0; i < grid.size(); i++) {
      for(int j = 0; j < grid[0].size(); j++) {
        if(time[i][j] != INT_MAX && time[i][j] > maxTime) maxTime = time[i][j];
        if(time[i][j] == INT_MAX && grid[i][j] == 1) return -1; // one orange is not reachable (cannot become rotten)
      }
    }
    return maxTime;
  }
};