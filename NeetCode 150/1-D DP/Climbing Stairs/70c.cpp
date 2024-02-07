class Solution {
public:
  int climbStairs(int n) {
    int prePrev = 1;
    int prev = 1;
    int cur = 1;
    for(int i = 2; i <= n; i++) {
      cur = prePrev + prev;
      prePrev = prev;
      prev = cur;
    }
    return cur;
  }
};