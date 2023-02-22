#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution {
public:
  bool canEat(vector<int> piles, long long howmuch, int h) {
    long long count = 0;
    for(int i = 0; i < piles.size(); i++){
      count+= ceil(piles[i] / (double)howmuch);
      if(count > h) return false;
    }
    return true;
  }

  int minEatingSpeed(vector<int>& piles, int h) {
    long long l = 0; long long r = *max_element(piles.begin(), piles.end());
    while(true) {
      long long index = (l+r)/2;
      // We don't use a real array from [1, ...,  n] so we need to index+1 to get the value we want e.g: index 3 is 4
      if(canEat(piles, index+1, h)) {
        if(!canEat(piles, index, h)) return index+1;
        r = index;
      } else {
        l = index;
      }
    }

    return -1;
  }
};

// LeetCode
int main() {
  Solution s;

  vector<int> v {312884470};
  s.minEatingSpeed(v, 968709470);
  return 0;
}