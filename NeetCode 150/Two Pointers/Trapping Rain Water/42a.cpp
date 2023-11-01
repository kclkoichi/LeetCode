#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int trap(vector<int>& height) {
    int curHeight = 0;
    vector<int> fromLeft = vector<int>(height.size());
    for(int i = 0; i < height.size(); i++) {
      curHeight = max(curHeight, height[i]);
      fromLeft[i] = curHeight;
    }

    curHeight = 0;
    vector<int> fromRight = vector<int>(height.size());
    for(int i = height.size()-1; i >= 0; i--) {
      curHeight = max(curHeight, height[i]);
      fromRight[i] = curHeight;
    }

    int count = 0;
    for(int i = 0; i < height.size(); i++) {
      int trapping = min(fromLeft[i], fromRight[i]) - height[i];
      if(trapping > 0) count += trapping;
    }

    return count;
  }
};