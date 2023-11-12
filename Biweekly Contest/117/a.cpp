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
  int dfs(int i, vector<int> people, int remaining, int limit) {
    if(i >= people.size()) return 0;
    if(remaining == 0) return 1;

    int sol = 0;

    if(people[i]+1 <= limit) {
      people[i]++;
      sol += dfs(i, people, remaining-1, limit);
      people[i]--;
    }
    sol += dfs(i+1, people, remaining, limit);

    return sol;
  }

  int distributeCandies(int n, int limit) {
    vector<int> people(3, 0);
    return dfs(0, people, n, limit);
  }
};