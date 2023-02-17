#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int index = digits.size() - 1;
      while(index >= 0 && digits[index] == 9) {
        digits[index] = 0;
        index--;
      }
      if(index == -1) {
        vector<int> ret = vector<int> { 1 };
        ret.insert(ret.end(), digits.begin(), digits.end());
        return ret;
      } else {
        digits[index]++;
      }
      return digits;
    }
};

// LeetCode
int main() {
  Solution s;
  vector<int> v = vector<int> {9};
  s.plusOne(v);
  return 0;
}