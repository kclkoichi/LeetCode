#include <string>
#include <list>
#include <unordered_map>
using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    if(t.size() == 1) {
      for(char c: s) {
        if(c == t[0]) return t;
      }
      return "";
    }

    pair<int, int> solIndices = make_pair(-1, s.size()); // it's wrong but it's longer than anything so solution will replace it

    // Info about wanted characters
    int requiredCount = t.size();
    unordered_map<char, int> wanted;
    for(char c: t) wanted[c]++;

    // Info about window
    int left = 0;
    int right = 0;

    while(right < s.size()) {
      char cur = s[right];
      if(wanted.find(cur) != wanted.end()) {
        wanted[cur]--;
        if(wanted[cur] >= 0) {
          requiredCount--;
        }
      }
      if(requiredCount == 0) {
        // invalidate to the maximum
        while(requiredCount < 2) {
          // smaller solution
          if(requiredCount == 0) {
            if(right - left < solIndices.second - solIndices.first) {
              solIndices.first = left;
              solIndices.second = right;
            }
          }
          cur = s[left];
          if(wanted.find(cur) != wanted.end()) {
            wanted[cur]++;
            if(wanted[cur] > 0) {
              requiredCount++;
            }
          }
          left++;
        }
        // Re-add wanted char
        left--;
        wanted[s[left]]--; // s at index left is the char
        requiredCount--;
      }
      right++;
    }

    if(solIndices.first == -1) return ""; // there was no sol
    
    // index, length
    return s.substr(solIndices.first, solIndices.second - solIndices.first + 1); // between indices, inclusive of both
  }
};