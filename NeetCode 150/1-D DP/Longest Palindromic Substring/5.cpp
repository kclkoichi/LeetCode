#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int start = 0;
    int end = s.size()-1;
    while(start < end) {
      if(s[start] != s[end]) return false;
      start++; end--;
    }
    return true;
  }

  string longestPalindrome(string s) {
    for(int i = s.size(); i >= 0; i--) {
      for(int j = 0; j+(i-1)<s.size(); j++) {
        if(isPalindrome(s.substr(j,i))) return s.substr(j,i);
      }
    }
    return "?"; // should never happen
  }
};