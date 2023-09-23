#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// O(1) memory
class TwoPointerSolution {
public:
  int trap(vector<int>& height) {
    int sum = 0;
    int l = 0; int lmax = height[0];
    int r = height.size()-1; int rmax = height[height.size()-1];

    int cur = -1;
    while (l != r) {
      if(rmax < lmax) {
        r--;
        cur = height[r];
        if(min(lmax, rmax) - cur > 0) sum += min(lmax, rmax) - cur;
        rmax = max(rmax, cur);
      } else {
        l++;
        cur = height[l];
        if(min(lmax, rmax) - cur > 0) sum += min(lmax, rmax) - cur;
        lmax = max(lmax, cur);
      }
    }
    return sum;
  }
};

// O(n) memory
class ArraySolution {
public:
  int trap(vector<int>& height) {
    vector<int> left = vector<int>(height.size());
    vector<int> right = vector<int>(height.size());
    int curMax = 0;
    for(int i = 0; i < height.size(); i++) {
      curMax = max(curMax, height[i]);
      left[i] = curMax;
    }
    curMax = 0;
    for(int i = height.size() - 1; i > -1; i--) {
      curMax = max(curMax, height[i]);
      right[i] = curMax;
    }
    int res = 0;
    for(int i = 0; i < height.size(); i++) {
      res += (min(left[i], right[i]) - height[i]);
    }

    return res;
  }
};

int main() {
  TwoPointerSolution s;
  vector<int> v { 0,1,0,2,1,0,1,3,2,1,2,1 };
  cout << s.trap(v) << endl;
  return 0;
}
