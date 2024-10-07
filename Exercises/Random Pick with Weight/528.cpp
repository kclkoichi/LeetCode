#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<pair<int, int>> v;
  int max = 0;

  Solution(vector<int>& w) {
    for(int i = 0; i < w.size(); i++) {
      max += w[i];
      v.push_back(make_pair(max, i));
    }
  }
  
  int pickIndex() {
    auto cmp = [](int a, pair<int,int> b) {
      return a < b.first;
    };
    return upper_bound(v.begin(), v.end(), rand() % max, cmp)->second;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */