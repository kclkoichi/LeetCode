#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      if(cost.size() < 2) return 0;
      int twoPrev = cost[0];
      int prev = cost[1];
      int index = 2;
      while(index < cost.size()) {
        int actual = cost[index] + min(twoPrev, prev);
        twoPrev = prev; prev = actual;
        index++; 
      }
      return min(twoPrev, prev); // 0 (cost of being out, at end of array) + min(twoPrev, prev) so min of last 2 indexes with a cost
    }
};