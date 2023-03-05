#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    string res = "";
    int resLen = 0;
    for(int i = 0; i < s.size(); i++) {
      // Odd length palindrome case
      int l = i, r = i;
      while(l >= 0 && r < s.size() && s[l] == s[r]) {
        if(r-l+1 > resLen) {
          resLen = r-l+1;
          res=s.substr(l,resLen);
        }
        l--; r++;
      }
      // Even length palindrome case
      l = i;
      r = i+1;
      while(l >= 0 && r < s.size() && s[l] == s[r]) {
        if(r-l+1 > resLen) {
          resLen = r-l+1;
          res=s.substr(l,resLen);
        }
        l--; r++;
      }
    }
    return res;
  }
};