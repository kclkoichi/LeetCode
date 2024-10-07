#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
  // can binary search on solution size: l = 1; r = s.size() and so on
  int longestRepeatingSubstring(string s) {
    for(int size = s.size() - 1; size >= 1; size--) {
      unordered_set<string> substrings;
      for(int i = 0; i <= s.size() - size; i++) {
        string sub = s.substr(i, size);
        if(substrings.find(sub) != substrings.end()) {
          return size; // we found same substring!
        }
        substrings.insert(sub);
      }
    }
    return 0;
  }
};