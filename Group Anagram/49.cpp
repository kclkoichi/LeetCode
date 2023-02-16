#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool anagram(string a, string b) {
      unordered_map<char, int> mapping;
      for(char c : a) {
        mapping[c]++;
      }
      for(char c : b) {
        if(mapping.find(c) == mapping.end()) return false;
        if(--mapping.find(c)->second < 0) return false;
      }
      for(auto z : mapping) {
        if(z.second != 0) return false;
      }
      return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<bool> grouped = vector<bool>(strs.size());
      vector<vector<string>> sol;
      for(int i = 0; i < strs.size(); i++) {
        if(!grouped[i]) {
          grouped[i] = true;
          vector<string> vs; vs.push_back(strs[i]);
          for(int j = i+1; j < strs.size(); j++) {
            if(!grouped[j]) {
              if(anagram(strs[i], strs[j])) {
                vs.push_back(strs[j]);
                grouped[j] = true;
            }
            }
          }
          sol.push_back(vs);
        }
      }
      return sol;
    }
};