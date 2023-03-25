#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int recursion(int i, string& s, vector<int>& memo) {
    int count = 0;
    // Base Case
    if(i >= s.size()) return 1;
    if(s[i] == '0') return 0;
    // Use memorisation if possible
    if(memo[i] != 0) return memo[i];
    // Take one
    count += recursion(i+1, s, memo);
    // If can add the world where Take two 
    if((i < s.size() - 1) && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) count += recursion(i+2, s, memo);
    memo[i] = count;
    return count;
  }
  int numDecodings(string s) {
    vector<int> memo = vector<int>(s.size());
    return recursion(0, s, memo);
  }
};

class Solution {
public:
  // Bottom-up (Iterative)
  int numDecodings(string s) {
    vector<int> dp = vector<int>(s.size()+1);
    dp[s.size()] = 1;
    int count = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
      count = 0;
      if(s[i] == '0') continue;
      count += dp[i+1];
      if((i < s.size() - 1) && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) count += dp[i+2];
      dp[i] = count;
    }
    return count;
  }
};