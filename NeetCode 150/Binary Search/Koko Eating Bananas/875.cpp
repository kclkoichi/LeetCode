#include <vector>
using namespace std;

class Solution {
public:
  bool canEat(vector<int> piles, int howmuch, int h) {
    int count = 0;
    for(int i = 0; i < piles.size(); i++){
      while(piles[i]>0) {
        piles[i]-=howmuch;
        count++;
        if(count > h) return false;
      }
    }
    return true;
  }

  int minEatingSpeed(vector<int>& piles, int h) {
    int i = 1;
    while(!canEat(piles, i, h)) {
      i++;
    }
    return i;
  }
};