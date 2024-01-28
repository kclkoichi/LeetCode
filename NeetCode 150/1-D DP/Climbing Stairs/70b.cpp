class Solution {
public:
  int climbStairs(int n) {
    int prePrev = 1;
    int prev = 1;
    for(int i = 2; i <= n; i++) {
      int next = prePrev + prev;
      prePrev = prev;
      prev = next;
    }
    return prev;
  }
};
