#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int max = 0;

    vector<vector<int>> dp = vector<vector<int>>(nums1.size() + 1, vector<int>(nums2.size() + 1));
    for(int i = nums1.size() - 1; i >= 0; i--) {
      for(int j = nums2.size() - 1; j >= 0; j--) {
        if(nums1[i] == nums2[j]){
          dp[i][j] = dp[i+1][j+1] + 1;
          if(max < dp[i][j]) max = dp[i][j];
        } else {
          dp[i][j] = 0;
        }
      }
    }

    return max;
  }
};