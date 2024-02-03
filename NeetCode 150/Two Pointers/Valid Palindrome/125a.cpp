#include <string>
using namespace std;

class Solution {
public:
  string clean(string s) {
    string cur = "";
    for(char c: s) {
      if(c >= 'a' && c <= 'z') {
        cur += c;
      } else if(c >= 'A' && c <= 'Z') {
        cur += tolower(c);
      } else if(c >= '0' && c <= '9') {
        cur += c;
      }
    }
    return cur;
  }

  bool isPalindrome(string s) {
    string cleanedS = clean(s);
    int l = 0;
    int r = cleanedS.size() - 1;
    while(l < r) {
      if(cleanedS[l] != cleanedS[r]) return false;
      l++;
      r--;
    }
    return true;
  }
};
