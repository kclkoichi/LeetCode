#include <map>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    string countingSort(string s) {
      string sorted = "";
      vector<int> counter = vector<int>(26);
      for(char c : s) counter[c - 'a']++;
      for(int i = 0; i < counter.size(); i++) {
        if(counter[i] > 0) {
          sorted += (char)(i+'a') + to_string(counter[i]);
        }
      }
      return sorted;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string> > mapping;
      for(int i = 0; i < strs.size(); i++) {
        string sorted = countingSort(strs[i]);
        if(mapping.find(sorted) == mapping.end()) {
          mapping[sorted] = vector<string> { strs[i] };
        } else {
          mapping[sorted].push_back(strs[i]);
        }
      }
      vector<vector<string>> sol;
      for(auto a : mapping) sol.push_back(a.second);
      return sol;
    }
};