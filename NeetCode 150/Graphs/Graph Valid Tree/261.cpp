#include <vector>
using namespace std;

class UFDS {
public:
  // number of sets
  int count;
  vector<int> v;

  UFDS(int n) {
    count = n;
    v = vector<int>(n);
    for(int i = 0; i < n; i++) v[i] = i; // representative of its group is itself
  }

  // Get representative of a node AND compress path
  int find(int a) {
    vector<int> toUpdate; // all these nodes are gonna map to the representative of the set
    while(v[a] != a) {
      toUpdate.push_back(a);
      a = v[a];
    }
    for(int node : toUpdate) {
      v[node] = a;
    }
    return a;
  }

  bool isSameSet(int a, int b) {
    return find(a) == find(b);
  }

  // union 2 sets
  void join(int a, int b) {
    if(isSameSet(a, b)) return;
    v[find(b)] = v[a]; // now, a has the same representative as b
    count--;
  }

  int numberOfSets() {
    return count;
  }
};

class Solution {
public:
  bool validTree(int n, vector<vector<int>>& edges) {
    UFDS uf = UFDS(n);
    for(vector<int> edge: edges) {
      int a = edge[0];
      int b = edge[1];
      if(uf.isSameSet(a,b)) return false; // we have a cycle
      uf.join(a,b);
    }
    return uf.numberOfSets() == 1; // tree is connected
  }
};