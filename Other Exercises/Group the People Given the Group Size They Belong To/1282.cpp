#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    unordered_map<int, vector<int>> groups;
    for(int i = 0; i < groupSizes.size(); i++) {
      int size = groupSizes[i];
      groups[size].push_back(i);
    }

    vector<vector<int>> res;
    for(auto [size, ids]: groups) {
      vector<int> cur = vector<int>();
      int i = 0;
      for(int id: ids) {
        if(i == size) {
          i = 0;
          res.push_back(cur);
          cur = vector<int>();
        }
        cur.push_back(id);
        i++;
      }
      res.push_back(cur);
    }

    return res;
  }
};
