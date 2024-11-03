#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// binary search (could have used lower_bound)
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

    vector<int> aIndices;
    for(int i = 0; i <= sSize - aSize; i++) {
      if(s.substr(i, a.size()) == a) aIndices.push_back(i);
    }

    vector<int> bIndices;
    for(int i = 0; i <= (int) sSize - bSize; i++) {
      if(s.substr(i, b.size()) == b) bIndices.push_back(i);
    }

    for(int i: aIndices) {
      int l = 0;
      int r = bIndices.size() - 1;
      while(l <= r) {
        int mid = (l + r)/2;
        if(abs(bIndices[mid] - i) <= k) {
          res.push_back(i);
          break;
        }
        if(bIndices[mid] > i + k) {
          r = mid-1;
        } else {
          l = mid+1;
        }
      }
    }

    return res;
  }
};
