#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int,int>> numsWithIndex = vector<pair<int,int>>();
    for(int i = 0; i < nums.size(); i++) numsWithIndex.push_back(make_pair(nums[i], i));
    sort(numsWithIndex.begin(), numsWithIndex.end(), [](pair<int,int> a, pair<int,int> b) {
      return a.first < b.first;
    });
    int l = 0;
    int r = numsWithIndex.size()-1;
    while(l != r) {
      if(numsWithIndex[l].first + numsWithIndex[r].first == target) return {numsWithIndex[l].second, numsWithIndex[r].second};
      if(numsWithIndex[l].first + numsWithIndex[r].first < target) {
        l++;
      } else {
        r--;
      }
    }
    return {-1, -1}; // have one sol so cannot happen
  }
};