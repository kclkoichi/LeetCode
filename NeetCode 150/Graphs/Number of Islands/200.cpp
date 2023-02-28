#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) return; // out of bounds
        if(grid[i][j] == '0') return; // out of island
        grid[i][j] = '0'; // it was 1 (island)
        dfs(grid, i, j+1); // N
        dfs(grid, i+1, j); // E
        dfs(grid, i, j-1); // S
        dfs(grid, i-1, j); // W
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};