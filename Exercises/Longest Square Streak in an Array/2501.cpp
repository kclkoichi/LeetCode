#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int longestSquareStreak(vector<int>& nums) {
    int res = 0;
    unordered_set<long long> numbers;
    for(int n: nums) numbers.insert(n);

    // floor(sqrt(100000)) = 316
    for(int i = 2; i <= 316; i++) {
      int count = 0;
      long long mult = i;
      while(numbers.find(mult) != numbers.end()) {
        count++;
        mult = mult * mult;
      }
      res = max(count, res);
    }

    return res == 0 || res == 1 ? -1 : res; // We don't want subsequence of size 0 nor 1
  }
};
