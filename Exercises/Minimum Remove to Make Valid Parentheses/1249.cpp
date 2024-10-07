#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string minRemoveToMakeValid(string s) {
    // Know how many closing we have in the future for each index
    vector<int> haveClosing(s.size());
    int closeCount = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
      if(s[i] == ')') closeCount++;
      haveClosing[i] = closeCount;
    }

    int needClosing = 0;
    string res;
    for(int i = 0; i < s.size(); i++) {
      char cur = s[i];
      if(cur == '(') {
        // If we have enough closing in the future, then can have '('
        if(haveClosing[i] - needClosing > 0) {
          needClosing++;
          res += '(';
        }
      } else if(cur == ')') {
        // If we don't need ')', skip.
        if(needClosing > 0) {
          needClosing--;
          res += ')';
        }
      } else {
        res += cur;
      }
    }

    return res;
  }
};