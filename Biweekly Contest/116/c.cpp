#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int distinctValues(vector<int> v) {
    unordered_set<int> values;
    for(int i : v) values.insert(i);
    return values.size();
  }
  int sumCounts(vector<int>& nums) {
    int count = 0;
    for(int size = 1; size <= nums.size(); size++){
      for(int j = 0; j <= nums.size() - size; j++) {
        vector<int> cur;
        for(int i = j; i < j + size; i++) {
          cur.push_back(nums[i]);
        }
        int vals = distinctValues(cur);
        count += vals*vals;
      }
    }
    return count;
  }
};