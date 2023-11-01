#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int area(int l, int heightL, int r, int heightR) {
    return min(heightL, heightR) * (r-l);
  }

  // Move left or right, choose the smallest height between both of them
  // Reason: you already got the maximum possible area for the smallest, so let's hope the next one is higher and will give a bigger total area!
  int maxArea(vector<int>& height) {
    int l = 0;
    int r = height.size() - 1;
    int maxArea = 0;
    while(l < r) {
      maxArea = max(maxArea, area(l, height[l], r, height[r]));
      if(height[l] <= height[r]) {
        l++;
      } else {
        r--;
      }
    }
    return maxArea;
  }
};