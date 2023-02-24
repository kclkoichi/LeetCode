#include <vector>
#include <queue>
#include <math.h>  
using namespace std;

class Solution {
public:
  double euclidean_dist(int x, int y) {
    return sqrt(pow((x-0), 2)+pow((y-0), 2)); // the other point is [0,0]
  }

  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<double, vector<int>>> min_pq;
    for(vector<int> v : points) {
      min_pq.push(make_pair(euclidean_dist(v[0],v[1]) * -1, v)); // manhattan distance
    }
    vector<vector<int>> sol;
    for(int i = 0; i < k; i++) {
      sol.push_back(min_pq.top().second);
      min_pq.pop();
    }
    return sol;
  }
};