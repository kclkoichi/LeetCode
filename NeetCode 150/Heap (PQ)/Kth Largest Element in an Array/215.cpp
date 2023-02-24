#include <vector>
#include <random>
using namespace std;

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    vector<int> smaller;
    vector<int> greater;
    bool found = false;
    k = nums.size() + 1 - k; // I want kth smallest
    while(!found) {
      int countEqual = 0;
      int i = rand() % nums.size();
      int pivot = nums[i];
      // Partition
      for(int j = 0; j < nums.size(); j++) {
        if(pivot < nums[j]) greater.push_back(nums[j]);
        if(nums[j] < pivot) smaller.push_back(nums[j]);
        if(nums[j] == pivot) countEqual++;
      }
      if(k >= smaller.size() + 1 && k <= smaller.size() + countEqual ) return pivot;
      if(k <= smaller.size()) {
        nums = smaller;
      } else {
        k = k - countEqual - smaller.size(); // kth smallest
        nums = greater;
      }
      smaller.clear();
      greater.clear();
      countEqual=0;
    }
    return -1;
  }
};

// LeetCode
int main() {
  Solution s;
  vector<int> v { 3,2,3,1,2,4,5,5,6 };
  s.findKthLargest(v, 4);
  return 0;
}