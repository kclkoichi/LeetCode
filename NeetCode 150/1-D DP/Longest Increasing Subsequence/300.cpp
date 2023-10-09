#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int getBiggerThanCount(int i, unordered_map<int, unordered_map<int, int>>& numToLISlength, const vector<int>& nums) {
    int max = 0;
    for(int j = i - 1; j >= 0; j--) {
      if(nums[i] > nums[j]) {
        int curLISlength = numToLISlength[j][nums[j]];
        if(curLISlength > max) {
          max = curLISlength;
        }
      }
    }
    return max + 1;
  }

  // O(n^2) time complexity
  int DPlengthOfLIS(vector<int>& nums) {
    unordered_map<int, unordered_map<int, int>> numToLISlength; // index -> number -> LISlength
    numToLISlength[0][nums[0]] = 1; // nothing is smaller before index 0; Longest Increasing Subsequence length is 1
    int max = 1;
    for(int i = 1; i < nums.size(); i++) {
      int cur = getBiggerThanCount(i, numToLISlength, nums);
      numToLISlength[i][nums[i]] = cur;
      if(cur > max) max = cur;
    }
    return max;
  }
};

class Solution {
public:
  // O(n log n) time complexity
  int lengthOfLIS(vector<int>& nums) {
    vector<int> sorted;
    sorted.push_back(nums[0]);
    for(int i = 1; i < nums.size(); i++) {
      if(nums[i] > sorted[sorted.size() - 1]) {
        sorted.push_back(nums[i]);
      } else {
        // Destroy the sorted array! We don't care about the content, we only want LIS Length

        // Overwrite the first one >= to nums[i] in sorted array
        sorted[lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin()] = nums[i];
      }
    }
    return sorted.size();
  }
};