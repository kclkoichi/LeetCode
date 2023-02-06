#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    void refresh(string &p, unordered_map<char, int> &target) {
      target.clear();
      for(char c : p) {
        target[c]++;
      }
    }

    // TLE :/
    vector<int> findAnagrams(string s, string p) {
      vector<int> sol;
      unordered_map<char, int> target;
      refresh(p, target);
      if(p.size() > s.size()) return sol;
      for(int i = 0; i < s.size() - p.size() + 1; i++) {

        bool toggle = true;
        for(int j = i; j < i + p.size(); j++) {

          if(target.find(s[j]) != target.end()) {
            target[s[j]]--;
            if(target[s[j]] < 0) toggle = false;
          } else {
            toggle = false;
            break;
          }

        }
        if(toggle) sol.push_back(i);
        refresh(p, target);
      }

      return sol;
    }
};

// LeetCode
int main() {
  Solution s;
  s.findAnagrams("cbaebabacd", "abc");
  return 0;
};