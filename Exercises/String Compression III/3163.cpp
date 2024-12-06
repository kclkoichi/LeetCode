#include <string>
using namespace std;

class Solution {
public:
  string compressedString(string word) {
    string res = "";

    char curC = word[0];
    int curCount = 1;
    for(int i = 1; i < (int) word.size(); i++) {
      char c = word[i];
      if(curC == c) {
        curCount++;
        if(curCount > 9) {
          res += '9';
          res += curC;
          curCount = 1;
        }
      } else {
        res += ('1' + curCount - 1);
        res += curC;
        curC = c;
        curCount = 1;
      }
    } 
    res += ('1' + curCount - 1);
    res += curC;
    return res;
  }
};
