#include <vector>
#include <queue>
using namespace std;

class UnionFind {
public:
  vector<int> sets;
  vector<int> rank;
  int setCount;

  UnionFind(int n) {
    setCount = n;
    rank = vector<int>(n);
    sets = vector<int>(n);
    for(int i = 0; i < n; i++) sets[i] = i;
  }

  // with path compression
  int findSetLead(int a) {
    vector<int> toCompress;
    while(a != sets[a]) {
      toCompress.push_back(a);
      a = sets[a];
    }
    for(int set: toCompress) sets[set] = a;
    return a;
  }

  bool isSameSet(int a, int b) {
    return findSetLead(a) == findSetLead(b);
  }

  void mergeSet(int a, int b) {
    if(isSameSet(a,b)) return;
    int leadA = findSetLead(a);
    int leadB = findSetLead(b);
    if(rank[leadA] == rank[leadB]) rank[leadB]++;
    if(rank[leadA] < rank[leadB]) {
      // put A below B
      sets[leadA] = leadB;
    } else {
      // put B below A
      sets[leadB] = leadA;
    }
    setCount--;
  }

  int getSetCount() {
    return setCount;
  }
};

class Solution {
public:
  int manhattanDistance(vector<int> a, vector<int> b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
  }

  int minCostConnectPoints(vector<vector<int>>& points) {
    // Sort by edge length ASC
    auto cmp = [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
      return a.first > b.first; // > because with < it gives a max heap, which is default pq in cpp
    };

    // <edgeLength, point 1, point 2>
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> allEdges;

    for(int i = 0; i < points.size(); i++) {
      vector<int> a = points[i];
      for(int j = i+1; j < points.size(); j++) {
        vector<int> b = points[j];
        allEdges.push(make_pair(manhattanDistance(a, b), make_pair(i, j)));
      }
    }

    /// Kruskal's algo ///
    int sum = 0;

    // Union Find to know which points are connected
    UnionFind uf = UnionFind(points.size());
    int prevCount = points.size();

    while(allEdges.size() > 0) {
      if(uf.getSetCount() == 1) return sum;
      pair<int, pair<int, int>> edge = allEdges.top();
      allEdges.pop();

      int length = edge.first;
      int a = edge.second.first;
      int b = edge.second.second;

      if(!uf.isSameSet(a, b)) {
        uf.mergeSet(a,b);
        sum += length;
      }
    }

    return sum;
  }
};
