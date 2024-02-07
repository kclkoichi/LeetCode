#include <string>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    string pal = "";
    // odd length
    for(int i = 0; i < s.size(); i++) {
      int l = i;
      int r = i;
      while(l >= 0 && r < s.size()) { 
        if(s[l] == s[r]) {
          l--; r++; 
        } else {
          break;
        }
      }
      l++; r--; // bringing them back
      if(r - l + 1 > pal.size()) pal = s.substr(l, r - l + 1);
    }

    // even length
    for(int i = 0; i < s.size() - 1; i++) {
      int l = i;
      int r = i+1;
      while(l >= 0 && r < s.size()) { 
        if(s[l] == s[r]) {
          l--; r++; 
        } else {
          break;
        }
      }
      l++; r--; // bringing them back
      if(r - l + 1 > pal.size()) pal = s.substr(l, r - l + 1);
    }

    return pal;
  }
};