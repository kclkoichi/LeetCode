#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
      unordered_set<int> visited;
      int rIndex = nums.size();
      int lIndex = 0;
      int index = (lIndex + rIndex)/2;
      while(visited.find(index) == visited.end()) {
        if(nums[index] == target) return index;
        visited.insert(index);
        if(nums[index] > target) rIndex = index;
        if(nums[index] < target) lIndex = index;
        index = (lIndex + rIndex)/2;
      }
      return -1;
    }
};

int main() {
  Solution s;
  vector<int> vect {2,5};
  cout << s.search(vect, 2);
  return 0;
};