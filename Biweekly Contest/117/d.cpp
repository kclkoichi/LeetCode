#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

class Solution {
public:
  long long maxSpending(vector<vector<int>>& values) {
    // value, indexInArray arrayIndex
    auto cmp = [](pair<ll, pair<int, int>> a, pair<ll, pair<int, int>> b) {
      if(a.second.first == a.second.first) return a.first > b.first;
      return a.second.first < b.second.first;
    };

    // DESC index, ASC val
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, decltype(cmp)> pq(cmp);

    for(int i = 0; i < values.size(); i++) {
      for(int j = 0; j < values[i].size(); j++) {
        pq.push(make_pair(values[i][j], make_pair(j, i)));
      }
    }

    ll sum = 0;
    ll counter = 1;
    while(!pq.empty()) {
      sum += counter * pq.top().first;
      counter++;
      pq.pop();
    }
    return sum;

  }
};