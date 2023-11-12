#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool dfs(string& s, int i, vector<string>& wordDict, vector<bool>& tried) {
    if(i == s.size()) return true; // We formed our word!
    if(tried[i]) return false; // Already tried from this index, no solution
    for(string word: wordDict) {
      // If correct, dfs
      if(i + word.size() <= s.size() && s.substr(i, word.size()) == word) {
        if(dfs(s, i+word.size(), wordDict, tried)) return true;
      }
    }
    tried[i] = true; // we tried, we found no solution
    return false; // We tried to add everything, no success
  }

  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> tried(s.size(), false);
    return dfs(s, 0, wordDict, tried);
  }
};
