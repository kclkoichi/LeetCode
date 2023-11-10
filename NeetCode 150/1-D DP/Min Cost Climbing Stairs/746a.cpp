#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size());
    int preprev = cost[0];
    int prev = cost[1];
    for(int i = 2; i < dp.size(); i++) {
      int actual = min(preprev, prev) + cost[i];
      preprev = prev;
      prev = actual;
    }
    return min(preprev, prev);
  }
};