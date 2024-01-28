#include <iostream>
#include <math.h>
#include <algorithm> // max
#include <string>
#include <algorithm> // sort, stable_sort

#include <vector>
#include <list>
#include <stack>
#include <queue> // and MAX priority queue
#include <deque>

#include <set> // BBST (and multiset)
#include <map> // BBST (and multimap)
#include <unordered_set> // Hash Table, boolean
#include <unordered_map> // Hash Table, map to something
using namespace std;

typedef long long ll;

class Solution {
public:
  bool validateNetwork(int n, vector<list<vector<int>>>& newAL, unordered_set<int>& curSet, int maxDistance) {
    for(int cur: curSet) {
      vector<int> distances(n, -1);
      distances[cur] = 0;

      auto cmp2 = [](vector<int> a, vector<int> b) {
        return a[1] > b[1];
      };

      priority_queue<vector<int>, vector<vector<int>>, decltype(cmp2)> pq(cmp2); 
      pq.push({cur, 0});
      
      // Dijkstra


      for(int dist: distances) {
        if(dist > maxDistance) return false;
      }
    }
    return true;
  }

  bool valid(int n, vector<list<vector<int>>>& AL, unordered_set<int>& curSet, int maxDistance) {
    // neighbour, dist
    vector<list<vector<int>>> newAL(n);
    for(int exist: curSet) newAL[exist] = AL[exist];
    for(int i = 0; i < n; i++) {
      auto it = newAL[i].begin();
      if(it != newAL[i].end()) {
        if(curSet.find((*it)[0]) == curSet.end()) {
          newAL[i].erase(it);
          it = newAL[i].begin();
        } else {
          it++;
        }
      }
    }

    return validateNetwork(n, newAL, curSet, maxDistance);
  }

  int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
    // Build AL
    vector<list<vector<int>>> AL(n, list<vector<int>>());
    for(vector<int> road: roads) {
      int a = road[0];
      int b = road[1];
      int dist = road[2];
      AL[a].push_back({b, dist});
      AL[b].push_back({a, dist});
    }

    int count = 1 + n; // Remove all + Remove all except 1 node
    
    // From size 2 till keep all
    for(int size = 2; size <= n; size++) {
      for(int i = 0; i < n; i++) {

        bool invalid = false;
        unordered_set<int> curSet;
        for(int a = i; a < i + size - 1; a++) {
          curSet.insert(a);
          if(a == n) invalid = true;
          if(invalid) break;
        }
        if(invalid) break;

        for(int curUnique = size - 1; curUnique < n; curUnique++) {
          curSet.insert(curUnique);
          if(valid(n, AL, curSet, maxDistance)) count++;
          curSet.erase(curUnique);
        }
      }

    }

    return count;
  }
};
