#include <vector>
using namespace std;

class UnionFind {                                // OOP style
private:
  vector<int> p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    --numSets;                                   // a union reduces numSets
  }
};

class Solution {
public:
  int earliestAcq(vector<vector<int>>& logs, int n) {
    auto cmp = [](vector<int> a, vector<int> b) {
      return a[0] < b[0];
    };
    sort(logs.begin(), logs.end(), cmp);

    UnionFind uf = UnionFind(n);
    int time = -1;
    for(vector<int> log: logs) {
      time = log[0];
      uf.unionSet(log[1], log[2]);
      if(uf.numDisjointSets() == 1) break;
    }
    return (uf.numDisjointSets() == 1) ? time : -1;
  }
};