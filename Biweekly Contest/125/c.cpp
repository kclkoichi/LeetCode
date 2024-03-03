#include <vector>
using namespace std;

class Solution {
public:
  void dfs(int cur, int origin, int curDist, vector<vector<int>>& dist, vector<bool>& vis, vector<vector<pair<int, int>>>& AL) {
    if(vis[cur]) return;
    vis[cur] = true;

    dist[origin][cur] = curDist;
    for(auto p: AL[cur]) {
      int neighbour = p.first;
      int d = p.second;
      dfs(neighbour, origin, curDist + d, dist, vis, AL);
    }
  }

  void childrenFrom(vector<int>& children, int cur, vector<vector<pair<int, int>>>& AL, vector<bool>& vis) {
    if(vis[cur]) return;
    vis[cur] = true;
    children.push_back(cur);
    for(auto p: AL[cur]) {
      childrenFrom(children, p.first, AL, vis);
    }
  }

  vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
    int n = 0; // number of nodes
    for(vector<int> edge: edges) {
      n = max(n, max(edge[0], edge[1]));
    }
    n++;

    vector<vector<pair<int, int>>> AL(n); // <neighbour, dist>
    for(vector<int> edge: edges) {
      AL[edge[0]].push_back(make_pair(edge[1], edge[2]));
      AL[edge[1]].push_back(make_pair(edge[0], edge[2]));
    }

    vector<vector<int>> dist(n, vector<int>(n, -1)); // -1 for unconnectable
    for(int i = 0; i < n; i++) {
      vector<bool> vis(n);
      dfs(i, i, 0, dist, vis, AL);
    }

    vector<int> res(n);

    for(int curNode = 0; curNode < n; curNode++) {
      for(int ai = 0; ai < AL[curNode].size(); ai++) {
        int a = AL[curNode][ai].first;
        vector<int> childrenFromA;
        vector<bool> visA(n); visA[curNode] = true;
        childrenFrom(childrenFromA, a, AL, visA);

        for(int bi = ai+1; bi < AL[curNode].size(); bi++) {

          int b = AL[curNode][bi].first;
          vector<int> childrenFromB;
          vector<bool> visB(n); visB[curNode] = true;
          childrenFrom(childrenFromB, b, AL, visB);

          int count = 0;
          for(int ca: childrenFromA) {
            for(int cb: childrenFromB) {
              int distA = dist[curNode][ca];
              int distB = dist[curNode][cb];
              if((distA % signalSpeed == 0) && (distB % signalSpeed == 0)) count++;
            }
          }
          res[curNode] += count;
        }
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  vector<int> v1 = {0,6,3};
  vector<int> v2 = {6,5,3};
  vector<int> v3 = {0,3,1};
  vector<int> v4 = {3,2,7};
  vector<int> v5 = {3,1,6};
  vector<int> v6 = {3,4,2};
  vector<vector<int>> vvi = {v1, v2, v3, v4, v5, v6};
  s.countPairsOfConnectableServers(vvi, 3);
  return 0;
}
