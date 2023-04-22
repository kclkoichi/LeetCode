#include <vector>
#include <list>
#include <set>
using namespace std;

class Solution {
public:
  int maxInt = 1e9; // to avoid overflow
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // Distances to nodes
    vector<int> dist = vector<int>(n+1, maxInt); dist[k] = 0; // k is source

    // Adjacency List [from](to, cost)
    vector<list<pair<int,int>>> AL (n+1, list<pair<int,int>>());
    for(vector<int> v : times) AL[v[0]].push_back(make_pair(v[1], v[2]));
    
    // set is BST, iterating is in increasing order
    set<pair<int,int>> pq;
    for(int i = 1; i <= n; i++) pq.insert(make_pair(dist[i], i));

    // Dijkstra's algo
    while (!pq.empty()) {
      pair<int, int> shortest = *pq.begin(); pq.erase(pq.begin());
      int from = shortest.second;
      for(pair<int,int> p : AL[from]) {
        int to = p.first;
        int cost = p.second;
        // Relax if possible
        if(dist[from] + cost < dist[to]) {
          pq.erase(pq.find({dist[to], to}));
          dist[to] = dist[from] + cost;
          pq.insert(make_pair(dist[to], to));
        }
      }
    }

    int m = *max_element(dist.begin()+1, dist.end());
    return m == maxInt ? -1 : m;
  }
};

int main() {
  Solution s;
  vector<vector<int>> v {vector<int>{2,1,1}, vector<int>{2,3,1}, vector<int>{3,4,1}};
  s.networkDelayTime(v, 4, 2);
}