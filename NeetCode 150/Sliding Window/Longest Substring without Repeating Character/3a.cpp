#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if(s.size() == 0) return 0;
    unordered_set<char> hashSet;
    hashSet.insert(s[0]);
    int l = 0;
    int r = 1;
    int count = 1;
    while(r < s.size()) {
      if(hashSet.find(s[r]) == hashSet.end()) {
        hashSet.insert(s[r]);
        count = max(count, r - l + 1);
      } else {
        char toEliminate = s[r];
        while(s[l] != toEliminate) {
          hashSet.erase(s[l]);
          l++;
        }
        // don't erase at the repeating char, but move l one last time to avoid having the char twice in the range
        l++;
      }
      r++;
    }
    return count;
  }
};