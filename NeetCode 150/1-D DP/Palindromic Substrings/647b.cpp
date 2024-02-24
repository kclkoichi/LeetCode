#include <string>
using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    int count = 0;
    for(int i = 0; i < s.size(); i++) {
      int l = i;
      int r = i;
      // odd
      while(l >= 0 && r < s.size() && s[l] == s[r]) {
        count++;
        l--;
        r++;
      }
      // even
      if(i == s.size() - 1) break;
      l = i;
      r = i+1;
      while(l >= 0 && r < s.size() && s[l] == s[r]) {
        count++;
        l--;
        r++;
      }
    }
    return count;
  }
};
