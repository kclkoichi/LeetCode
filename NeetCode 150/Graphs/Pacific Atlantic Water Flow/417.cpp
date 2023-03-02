#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> sol;
    vector<vector<bool>> reachablePacific (heights.size(), vector<bool> (heights[0].size()));
    vector<vector<bool>> reachableAtlantic (heights.size(), vector<bool> (heights[0].size()));
    // From West (Pacific)
    for(int i = 0; i < heights.size(); i++) {
      int col = 0;
      int cur = heights[i][col];
      while(col < heights[0].size()) {
        if(heights[i][col] < cur) break; // if next is smaller break
        reachablePacific[i][col] = true;
        cur = heights[i][col];
        col++;
      }
    }
    // From North (Pacific)
    for(int i = 0; i < heights[0].size(); i++) {
      int row = 0;
      int cur = heights[row][i];
      while(row < heights.size()) {
        if(heights[row][i] < cur) break;
        reachablePacific[row][i] = true;
        cur = heights[row][i];
        row++;
      }
    }
    // From East (Atlantic)
    for(int i = 0; i < heights.size(); i++) {
      int col = heights[0].size() - 1;
      int cur = heights[i][col];
      while(col >= 0) {
        if(heights[i][col] < cur) break;
        reachableAtlantic[i][col] = true;
        cur = heights[i][col];
        col--;
      }
    }
    // From South (Atlantic)
    for(int i = 0; i < heights[0].size(); i++) {
      int row = heights.size() - 1;
      int cur = heights[row][i];
      while(row >= 0) {
        if(heights[row][i] < cur) break;
        reachableAtlantic[row][i] = true;
        cur = heights[row][i];
        row--;
      }
    }

    for(int i = 0; i < heights.size(); i++) {
      for(int j = 0; j < heights[i].size(); j++) {
        cout << reachablePacific[i][j] << " ";
      }
      cout << "\n";
    }
    cout << "\n";
    for(int i = 0; i < heights.size(); i++) {
      for(int j = 0; j < heights[i].size(); j++) {
        cout << reachableAtlantic[i][j] << " ";
      }
      cout << "\n";
    }

    // Check intersection
    for(int i = 0; i < heights.size(); i++) {
      for(int j = 0; j < heights[i].size(); j++) {
        if(reachableAtlantic[i][j] && reachablePacific[i][j]) sol.push_back(vector<int> { i, j });
      }
    }
    return sol;
  }
};