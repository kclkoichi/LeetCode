#include <vector>
#include <queue>
using namespace std;

class UnionFind {                                // OOP style
private:
  vector<int> p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
};

class Solution {
public:
  int manhattanDist(vector<int>& a, vector<int>& b) {
    return abs(b[0] - a[0]) + abs(b[1] - a[1]);
  }

  int minCostConnectPoints(vector<vector<int>>& points) {
    priority_queue<pair<int, pair<int, int>>> minPq; // cost, pair of points (stored as index)
    for(int i = 0; i < points.size(); i++) {
      for(int j = i+1; j < points.size(); j++) {
        minPq.push(make_pair(-manhattanDist(points[i],points[j]), make_pair(i,j)));
      }
    }
    // Kruskal's algo for MST
    UnionFind ufds = UnionFind(points.size()); // number of points
    int cost = 0;
    while(!minPq.empty()) {
      int curCost = minPq.top().first;
      int a = minPq.top().second.first; 
      int b = minPq.top().second.second; 
      minPq.pop();
      int prevNum = ufds.numDisjointSets();
      ufds.unionSet(a, b);
      if(ufds.numDisjointSets() == prevNum) continue; // the points were already connected
      cost+=(curCost*-1);
      if(ufds.numDisjointSets() == 1) break; // everything is already connected
    }
    return cost;
  }
};