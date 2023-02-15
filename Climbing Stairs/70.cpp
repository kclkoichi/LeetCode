#include <vector>
using namespace std;

class Solution {
public:
    // it's... Fibonacci
    int climbStairs(int n) {
      if(n==1) return 1;
      vector<int> vect = vector<int>(n + 1);
      vect[0] = 1; vect[1] = 1;
      int i = 2;
      while(i < (n + 1)) {
        vect[i] = vect[i-2] + vect[i-1];
        i++;
      }
      return vect[i-1];
    }
};