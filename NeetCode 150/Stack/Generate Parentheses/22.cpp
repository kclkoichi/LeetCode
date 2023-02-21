#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  void dfs(vector<string>& result, string current, int open, int close) {
    if(close < open) return;
    // In C++ 0 == 0 == 1 (wtf)
    if((0 == close) && (close == open)) result.push_back(current);
    if(open > 0) {
      dfs(result, current+"(", open-1, close);
      // Try alternate universe where we used a ) instead
      dfs(result, current+")", open, close-1);
    } else {
      // No ( available anymore
      dfs(result, current+")", open, close-1);
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> result;
    string current = "";
    dfs(result, current, n, n);
    return result;
  }
};

// LeetCode
int main() {
  Solution s;
  s.generateParenthesis(3);
  return 0;
}