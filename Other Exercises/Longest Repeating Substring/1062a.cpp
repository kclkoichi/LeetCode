#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int longestRepeatingSubstring(string s) {
    int res = 0;
    for(int curSize = 1; curSize < s.size(); curSize++) {
      unordered_set<string> words;
      for(int i = 0; i - 1 + curSize < s.size(); i++) {
        string cur = s.substr(i, curSize);
        if(words.find(cur) != words.end()) {
          res = cur.size();
          break;
        } else {
          words.insert(cur);
        }
      }
    }
    return res;
  }
};