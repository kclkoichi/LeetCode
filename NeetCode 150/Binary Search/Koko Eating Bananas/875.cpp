#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int l = 1; int r = 1000000000;
    while(l < r) {
      int i = (l+r)/2;
      int count = 0;
      for(int bananas : piles) count += ceil(bananas / (double) i);
      if(count > h) {
        // cannot eat now, need to eat faster
        l = i+1;
      } else {
        r = i;
      }
    }

    return l;
  }
};

// LeetCode
int main() {
  Solution s;

  vector<int> v {312884470};
  s.minEatingSpeed(v, 968709470);
  return 0;
}