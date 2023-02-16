#include <map>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      map< map<char,int>, vector<string> > mapping;
      for(int i = 0; i < strs.size(); i++) {
        map<char,int> counter;
        for(char c : strs[i]) counter[c]++;
        if(mapping.find(counter) == mapping.end()) {
          mapping[counter] = vector<string> { strs[i] };
        } else {
          mapping.find(counter)->second.push_back(strs[i]);
        }
      }

      vector<vector<string>> sol;
      for(auto a : mapping) sol.push_back(a.second);
      return sol;
    }
};