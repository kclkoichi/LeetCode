#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s;
    for(int i : nums) s.insert(i);

    int size = 0;
    for(int i : nums) {
      // if starting number
      if(s.find(i-1) == s.end()) {
        int count = 0;
        int cur = i;
        while(s.find(cur) != s.end()) {
          count++;
          cur++;
        }
        size = max(size, count);
      }
    }
    return size;
  }
};