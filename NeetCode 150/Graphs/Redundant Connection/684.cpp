#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    vector<int> last = vector<int> { -1, -1 };
    unordered_set<int> seen;
    seen.insert(edges[0][0]);
    for(vector<int> edge : edges) {
      int a = edge[0];
      int b = edge[1];
      if(seen.find(a) != seen.end() && seen.find(b) != seen.end()) last = edge; // both already contained
      seen.insert(a);
      seen.insert(b);
    }
    return last;
  }
};