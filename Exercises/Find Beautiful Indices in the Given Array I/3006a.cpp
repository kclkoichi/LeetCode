#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// TLE
class Solution {
public:
  vector<int> beautifulIndices(string s, string a, string b, int k) {
    vector<int> res;

    // Need these because size() returns unsigned int.
    // Example: s.size() = 2, a.size() = 5
    // s.size() - a.size() = 18446744073709551613
    int sSize = (int) s.size();
    int aSize = (int) a.size();
    int bSize = (int) b.size();

    unordered_set<int> aIndices;
    for(int i = 0; i <= sSize - aSize; i++) {
      if(s.substr(i, a.size()) == a) aIndices.insert(i);
    }

    unordered_set<int> bIndices;
    for(int i = 0; i <= (int) sSize - bSize; i++) {
      if(s.substr(i, b.size()) == b) bIndices.insert(i);
    }


    for(int i = 0; i <= (int) sSize - aSize; i++) {
      if(aIndices.find(i) == aIndices.end()) continue;
      for(int j = max(0, i - k); j <= min((int) s.size() - 1, i + k); j++) {
        if(bIndices.find(j) != bIndices.end()) {
          res.push_back(i);
          break;
        }
      }
    }

    return res;
  }
};
