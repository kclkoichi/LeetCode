#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> sol;
    vector<vector<bool>> reachablePacific (heights.size(), vector<bool> (heights[0].size()));
    vector<vector<bool>> reachableAtlantic (heights.size(), vector<bool> (heights[0].size()));
    // West and North (Pacific)
    stack<vector<int>> pacificStack;
    for(int i = 0; i < heights.size(); i++) pacificStack.push(vector<int> { i, 0, -1 });
    for(int i = 0; i < heights[0].size(); i++) pacificStack.push(vector<int> { 0, i, -1 });
    // East and South (Atlantic)
    stack<vector<int>> atlanticStack;
    for(int i = 0; i < heights.size(); i++) atlanticStack.push(vector<int> { i, (int) heights[0].size() - 1, -1 });
    for(int i = 0; i < heights[0].size(); i++) atlanticStack.push(vector<int> { (int) heights.size() - 1, i, -1 });

    while(!pacificStack.empty()) {
      int row = pacificStack.top()[0];
      int col = pacificStack.top()[1];
      int prevVal = pacificStack.top()[2];
      pacificStack.pop();
      if(row < 0 || row > heights.size() - 1 || col < 0 || col > heights[0].size() - 1) continue; // invalid position
      // DFS
      if(!reachablePacific[row][col] && heights[row][col] >= prevVal) {
        reachablePacific[row][col] = true;
        prevVal = heights[row][col];
        pacificStack.push(vector<int> {row - 1, col, prevVal});
        pacificStack.push(vector<int> {row, col - 1, prevVal});
        pacificStack.push(vector<int> {row + 1, col, prevVal});
        pacificStack.push(vector<int> {row, col + 1, prevVal});
      }
    }

    while(!atlanticStack.empty()) {
      int row = atlanticStack.top()[0];
      int col = atlanticStack.top()[1];
      int prevVal = atlanticStack.top()[2];
      atlanticStack.pop();
      if(row < 0 || row > heights.size() - 1 || col < 0 || col > heights[0].size() - 1) continue; // invalid position
      // DFS
      if(!reachableAtlantic[row][col] && heights[row][col] >= prevVal) {
        reachableAtlantic[row][col] = true;
        prevVal = heights[row][col];
        atlanticStack.push(vector<int> {row - 1, col, prevVal});
        atlanticStack.push(vector<int> {row, col - 1, prevVal});
        atlanticStack.push(vector<int> {row + 1, col, prevVal});
        atlanticStack.push(vector<int> {row, col + 1, prevVal});
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