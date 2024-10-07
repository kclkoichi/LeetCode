#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
  int findPermutationDifference(string s, string t) {
    unordered_map<char, int> charToPosition;
    for(int i = 0; i < s.size(); i++) {
      charToPosition[s[i]] = i;
    }

    int res = 0;
    for(int i = 0; i < t.size(); i++) {
      res += abs(i - charToPosition[t[i]]);
    }
    return res;
  }
};
