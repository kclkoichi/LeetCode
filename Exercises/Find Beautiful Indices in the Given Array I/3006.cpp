#include <string>
#include <vector>
using namespace std;

// TLE
class Solution {
public:
  vector<int> beautifulIndices(string s, string a, string b, int k) {
    vector<int> res;

    for(int i = 0; i < s.size(); i++) {
      if(i > s.size() - a.size()) continue;
      if(s.substr(i, a.size()) != a) continue;
      for(int j = 0; j < s.size(); j++) {
        if(abs(j-i) > k) continue;
        if(j > s.size() - b.size()) continue;
        if(s.substr(j, b.size()) != b) continue;
        res.push_back(i);
        break;
      }
    }

    return res;
  }
};
