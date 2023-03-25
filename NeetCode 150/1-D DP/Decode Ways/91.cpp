#include <string>
using namespace std;

class Solution {
public:
  int recursion(int i, string& s) {
    int count = 0;
    // Base Case
    if(i >= s.size()) return 1;
    if(s[i] == '0') return 0;
    // Take one
    count += recursion(i+1, s);
    // If can add the world where Take two 
    if((i < s.size() - 1) && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) count += recursion(i+2, s);
    return count;
  }
  int numDecodings(string s) {
    return recursion(0, s);
  }
};