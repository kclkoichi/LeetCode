#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<string> removeSubfolders(vector<string>& folder) {
    vector<string> res;
    sort(folder.begin(), folder.end());
    res.push_back(folder[0]);
    
    for(int i = 1; i < folder.size(); i++) {
      string cur = folder[i];
      // might be a subdirectory
      if(res.back().size() < cur.size()) {
        string path = cur.substr(0, res.back().size());
        if(path == res.back() && cur[path.size()] == '/') {
          // It is a subdirectory so do nothing.
          // If the char after path is not /, it means that the it wasn't the same path (last dir has different name)
        } else {
          res.push_back(cur);
        }
      } else {
        res.push_back(cur);
      }
    }

    return res;
  }
};
