#include <vector>
using namespace std;

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int l = m-1;
    int r = n-1;
    int insert = nums1.size()-1;
    bool quit = false;
    while(insert >= 0) {
      if(l < 0) {
        nums1[insert] = nums2[r];
        r--;
      } else if(r < 0) {
        return;
      } else if(nums1[l] > nums2[r]) {
        nums1[insert] = nums1[l];
        l--;
      } else {
        // nums1[l] < nums2[r] or ==
        nums1[insert] = nums2[r];
        r--;
      }
      insert--;
    }
  }
};