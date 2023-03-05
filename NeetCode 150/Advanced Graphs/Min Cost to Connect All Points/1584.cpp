#include <vector>
#include <queue>
#include <map>
#include <set>
#include <math.h>
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
  int manhattanDist(vector<int> a, vector<int> b) {
    return abs(b[0] - a[0]) + abs(b[1] - a[1]);
  }

  int minCostConnectPoints(vector<vector<int>>& points) {
    priority_queue<pair<int, pair<vector<int>, vector<int>>>> minPq; // cost, pair of points
    for(int i = 0; i < points.size(); i++) {
      vector<int> a = points[i];
      for(int j = i+1; j < points.size(); j++) {
        vector<int> b = points[j];
        minPq.push(make_pair(-manhattanDist(a,b), make_pair(a,b)));
      }
    }
    // Kruskal's algo for MST
    UnionFind ufds = UnionFind(1000); // max of 1000 points
    int cost = 0;
    int j = 0;
    map<pair<int,int>, int> m; // to map point to index in UFDS
    while(!minPq.empty()) {
      int curCost = minPq.top().first;
      pair<vector<int>, vector<int>> curPoints = minPq.top().second; 
      minPq.pop();
      pair<int,int> a = make_pair(curPoints.first[0], curPoints.first[1]);
      pair<int,int> b = make_pair(curPoints.second[0], curPoints.second[1]);
      // Mapping points to index in UFDS
      if(m.find(a) == m.end()) m[a] = j++;
      if(m.find(b) == m.end()) m[b] = j++;
      int prevNum = ufds.numDisjointSets();
      ufds.unionSet(m[a], m[b]);
      if(ufds.numDisjointSets() == prevNum) continue; // the points were already connected
      cost+=(curCost*-1);
    }
    return cost;
  }
};