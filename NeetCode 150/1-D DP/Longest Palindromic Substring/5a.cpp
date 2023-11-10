#include <string>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int size = 1;
    int startAt = 0;
    for(int i = 0; i < s.size(); i++) {
      // odd length (not interested in size 1)
      int l = i-1;
      int r = i+1;
      int curSize = 1;
      while(l >= 0 && r < s.size()) {
        if(s[l] == s[r]) {
          curSize += 2;
          if(size < curSize) {
            startAt = l;
            size = curSize;
          }
        } else {
          break;
        }
        l--;
        r++;
      }

      // even length
      l = i;
      r = i+1;
      curSize = 0;
      while(l >= 0 && r < s.size()) {
        if(s[l] == s[r]) {
          curSize += 2;
          if(size < curSize) {
            startAt = l;
            size = curSize;
          }
        } else {
          break;
        }
        l--;
        r++;
      }
    }

    string longest = "";
    if(size > 1) {
      longest = s.substr(startAt, size);
    } else {
      longest = s[0];
    }

    return longest;
  }
};