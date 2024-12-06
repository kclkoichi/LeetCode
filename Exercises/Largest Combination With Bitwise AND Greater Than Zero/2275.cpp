#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  unordered_map<int, int> haveBit;

  void addToHaveBit(int binary) {
    int cur = 1;
    while(binary > 0) {
      if(binary % 2 == 1) {
        haveBit[cur]++;
        binary--;
      }
      binary /= 2;
      cur++;
    }
  }

  int largestCombination(vector<int>& candidates) {
    for(int bin: candidates) addToHaveBit(bin);
    int res = 1;
    // 2^30 apprx 1000000000, candidates[i] <= 10000000
    for(int i = 30; i >= 1; i--) {
      res = max(res, haveBit[i]);
    }
    return res;
  }
};