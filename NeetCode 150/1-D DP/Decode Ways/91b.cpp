#include <string>
using namespace std;

class Solution {
public:
  unordered_map<int, int> memo;

  // [1, 26] are valid
  bool valid(string snippet) {
    if(snippet.size() == 1 && snippet[0] != '0') return true;
    if(snippet.size() == 2 && snippet[0] == '1') return true;
    if(snippet.size() == 2 && snippet[0] == '2' && (snippet[1] >= '0' && snippet[1] <= '6')) return true;
    return false;
  }

  int recursion(string& s, int i) {
    if(memo.find(i) != memo.end()) return memo[i];
    if(i == s.size()) return 1;

    int count = 0;
    // Take 1
    string snippet = "";
    snippet += s[i];
    if(valid(snippet)) count += recursion(s, i+1);
    // Take 2
    if(i < s.size() - 1) {
      snippet += s[i+1];
      if(valid(snippet)) count += recursion(s, i+2);
    }
    memo[i] = count;
    return count;
  }

  int numDecodings(string s) {
    return recursion(s, 0);
  }
};
