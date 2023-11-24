#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int numIdenticalPairs(vector<int>& nums) {
    int count = 0;
    unordered_map<int, int> counter;
    for(int i = nums.size()-1; i >= 0; i--) {
      if(counter.find(nums[i]) != counter.end()) count += counter[nums[i]];
      counter[nums[i]]++;
    }
    return count;
  }
};
