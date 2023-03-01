#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> sol;
    vector<vector<bool>> reachable (heights.size(), vector<bool> (heights[0].size()));
    for(int i = 0; i < heights.size(); i++) {
      for(int j = 0; j < heights[i].size(); j++) {
        vector<vector<bool>> visited (heights.size(), vector<bool> (heights[i].size()));
        stack<vector<int>> st; 
        st.push(vector<int> {i, j});
        bool pacific = false;
        bool atlantic = false;
        // dfs
        while(!st.empty()) {
          int row = st.top()[0];
          int col = st.top()[1];
          st.pop();
          // Set visited
          if(visited[row][col]) continue;
          visited[row][col] = true;
          if(row == 0) {
            pacific = true;
          } else {
            if(reachable[row-1][col] && heights[row][col] >= heights[row-1][col]) { pacific = true; atlantic = true; break; }
            if(!visited[row-1][col] && heights[row][col] >= heights[row-1][col]) st.push(vector<int> { row-1, col }); // W
          }
          if(row == heights.size() - 1) {
            atlantic = true;
          } else {
            if(reachable[row+1][col] && heights[row][col] >= heights[row+1][col]) { pacific = true; atlantic = true; break; }
            if(!visited[row+1][col] && heights[row][col] >= heights[row+1][col]) st.push(vector<int> { row+1, col }); // E
          }
          if(col == 0) {
            pacific = true;
          } else {
            if(reachable[row][col-1] && heights[row][col] >= heights[row][col-1]) { pacific = true; atlantic = true; break; }
            if(!visited[row][col-1] && heights[row][col] >= heights[row][col-1]) st.push(vector<int> { row, col-1 }); // N
          }
          if(col == heights[i].size() - 1) {
            atlantic = true;
          } else {
            if(reachable[row][col+1] && heights[row][col] >= heights[row][col+1]) { pacific = true; atlantic = true; break; }
            if(!visited[row][col+1] && heights[row][col] >= heights[row][col+1]) st.push(vector<int> { row, col+1 }); // S
          }
          if(pacific && atlantic) break;
        }
        if(pacific && atlantic) {
          sol.push_back(vector<int> { i,j });
          reachable[i][j] = true;
        }
      }
    }
    return sol;
  }
};