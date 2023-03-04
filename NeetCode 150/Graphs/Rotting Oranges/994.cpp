#include <vector>
#include <math.h>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int,int>> q;
    int time = -1;
    int count = 0;
    for(int i = 0; i < grid.size(); i++) {
      for(int j = 0; j < grid[0].size(); j++) {
        if(grid[i][j] == 1) count++;
        if(grid[i][j] == 2) q.push(make_pair(i, j));
      }
    }
    if(count == 0) return 0; // there was no orange...
    
    vector<pair<int, int>> dir { make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1) };
    while(!q.empty()) {
      int size = q.size();
      while(size > 0) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(pair<int, int> p : dir) {
          if(row+p.first < 0 || col+p.second < 0 || row+p.first > grid.size() - 1 || col+p.second > grid[0].size() - 1) continue;
          if(grid[row+p.first][col+p.second] == 1) {
            grid[row+p.first][col+p.second] = 2; // now rotten
            count--;
            q.push(make_pair(row+p.first, col+p.second));
          }
        }
        size--;
      }
      time++; // one minute elapsed
    }

    return count == 0 ? time : -1;
  }
};