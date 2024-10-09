#include <string>
using namespace std;

class Solution {
public:
  int minAddToMakeValid(string s) {
    int count = 0;
    int open = 0;
    for(char c: s) {
      if(c == '(') {
        open++;
      } else {
        open--;
        if(open == -1) {
          open++;
          count++;
        }
      }
    }
    return count + open;
  }
};