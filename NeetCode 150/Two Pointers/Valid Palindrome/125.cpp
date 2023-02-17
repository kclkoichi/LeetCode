#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string newS = "";
        // for(char c : s) {
        //   if((int)c > 64 && (int)c < 91) {
        //     char cc = (int)c+32;
        //     newS += cc;
        //   }
        //   if((int)c > 96 && (int)c < 123) newS += c;
        // }
        for(char c : s) {
          if(isdigit(c)) newS += c;
          if(islower(c)) newS += c;
          if(isupper(c)) newS += tolower((c));
        }
        int b = newS.length() - 1;
        for(int i = 0; i < newS.length()/2; i++) {
          if(newS[i] != newS[b]) return false;
          b--;
        }
        return true;
    }
};

int main() {
  Solution s;
  s.isPalindrome("race a car");

  return 0;
};