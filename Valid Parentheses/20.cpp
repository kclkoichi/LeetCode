#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
      stack<char> sta;
        for(char c : s) {
          if(c == '{') sta.push('{');
          if(c == '(') sta.push('(');
          if(c == '[') sta.push('[');

          if(c == '}') {
            if(sta.size() == 0) return false;
             if(sta.top() != '{') return false;
             sta.pop();
          }
          if(c == ')') {
            if(sta.size() == 0) return false;
             if(sta.top() != '(') return false;
             sta.pop();
          }
          if(c == ']') {
            if(sta.size() == 0) return false;
             if(sta.top() != '[') return false;
             sta.pop();
          }
        }
      
      return sta.size() == 0;
    }
};