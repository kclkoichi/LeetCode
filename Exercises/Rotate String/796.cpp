#include <string>
using namespace std;

class Solution {
public:
  bool rotateString(string s, string goal) {
    // edge case, s and goal are not same size
    if(s.size() != goal.size()) return false;
    string doubleS = s + s;
    for(int i = 0; i < s.size(); i++) {
      if(doubleS[i] == goal[0] && doubleS[i+goal.size()-1] == goal[goal.size()-1]) {
        if(doubleS.substr(i, goal.size()) == goal) return true;
      }
    }
    return false;
  }
};