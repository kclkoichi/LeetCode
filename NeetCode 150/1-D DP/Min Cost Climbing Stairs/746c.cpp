#include <vector>
using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int nextNext = cost[cost.size()-1];
    int next = cost[cost.size()-2];
    int cur = min(next, nextNext);
    for(int i = cost.size()-3; i >= 0; i--) {
      cur = cost[i] + min(next, nextNext);
      nextNext = next;
      next = cur;
    }
    return min(next, nextNext);
  }
};