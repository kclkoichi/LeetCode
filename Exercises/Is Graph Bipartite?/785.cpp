#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  char getOpposite(char c) {
    return c == 'G'? 'R' : 'G';
  }

  // Colour graph in two colours!
  // Time O(N+E)    N is number of Node, E is number of Edge
  // Space O(N)
  bool isBipartite(vector<vector<int>>& graph) {
    int N = graph.size();
    vector<char> colours(N, '?');
    vector<bool> visited(N);

    for(int i = 0; i < N; i++) {
      if(visited[i]) continue;

      colours[i] = 'G'; // Arbitrarely choose colour of first node in CC
      queue<int> q; // to visit
      q.push(i);
      while(!q.empty()) {
        int cur = q.front();
        int color = colours[cur];
        q.pop();

        visited[cur] = true;
        for(int neighbour: graph[cur]) {
          if(color == colours[neighbour]) {
            // same color neighbour so not bipartite
            return false;
          } else if(getOpposite(color) == colours[neighbour]) {
            // opposite color neighbour so fine
          } else {
            // not visited yet
            colours[neighbour] = getOpposite(color);
            q.push(neighbour);
          }
        }
      }
    }
    return true;
  }
};