#include <string>
using namespace std;

class Solution {
public:
  string reverse(string s) {
    int l = 0;
    int r = s.size() - 1;
    while(l < r) {
      char lc = s[l];
      char rc = s[r];
      s[l] = rc;
      s[r] = lc;
      l++;
      r--;
    }
    return s;
  }

  string reverseWords(string s) {
    string result = "";
    string cur = "";
    for(char c : s) {
      if(c == ' ') {
        result += reverse(cur) + " ";
        cur = "";
      } else {
        cur += c;
      }
    }
    if(cur != "") result += reverse(cur);
    return result;
  }
};