#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  // a and b same size
  int diff(string a, string b) {
    int count = 0;
    for(int i = 0; i < a.size(); i++) {
      if(a[i] != b[i]) count++;
    }
    return count;
  }

  int minOperations(string s) {
    string s1 = "";
    string s2 = "";
    char cur = '0';
    for(int i = 0; i < s.size(); i++) {
      s1+=cur;
      cur = cur == '0' ? '1' : '0';
    }
    cur = '1';
    for(int i = 0; i < s.size(); i++) {
      s2+=cur;
      cur = cur == '0' ? '1' : '0';
    }

    return min(diff(s,s1), diff(s,s2));
  }
};