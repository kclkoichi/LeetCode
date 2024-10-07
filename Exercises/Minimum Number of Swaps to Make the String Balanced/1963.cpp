#include <string>
#include <stack>
using namespace std;

class Solution {
public:
  int minSwaps(string s) {
    int count = 0;

    int opened = 0;
    int closed = 0;
    int toSwap = s.size() - 1;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == '[') opened++;
      if(s[i] == ']') closed++;
      if(closed > opened) {
        count++;

        // Swap
        while(toSwap > i && s[toSwap] != '[') {
          toSwap--;
        }
        s[i] = '[';
        s[toSwap] = ']';

        closed--;
        opened++;
      }
    }
    return count;
  }
};
