#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // time complexity: O(n^2)
  vector<int> amountPainted(vector<vector<int>>& paint) {
    unordered_map<int, int> paintedMap;
    vector<int> res;
    for(vector<int> zone: paint) {
      int start = zone[0];
      int end = zone[1];
      int painted = 0;
      for(int i = start; i < end; i++) {
        if(paintedMap.find(i) == paintedMap.end()) {
          painted++;
          paintedMap[i] = end;
        } else {
          int prevEnd = paintedMap[i];
          paintedMap[i] = max(prevEnd, end); // optimiasation, next time we come at i we want to go furthest possible
          i = prevEnd - 1; // For now, we need to paint till max so need prevEnd to be sure to paint till end
          // -1 because it's gonna i++
        }
      }
      res.push_back(painted);
    }
    return res;
  }
};