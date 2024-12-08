#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> vis = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size()));
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    count++;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        if(!(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())) continue;
                        if(vis[x][y]) continue;
                        vis[x][y] = true;

                        if(grid[x][y] == '1') {
                            q.push(make_pair(x-1, y));
                            q.push(make_pair(x+1, y));
                            q.push(make_pair(x, y-1));
                            q.push(make_pair(x, y+1));
                        }
                    }
                }
            }
        }
        return count;
    }
};