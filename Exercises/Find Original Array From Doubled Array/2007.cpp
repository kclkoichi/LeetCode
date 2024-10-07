#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> findOriginalArray(vector<int>& changed) {
    // edge case: odd number of elements
    if(changed.size() % 2 == 1) return {};

    unordered_map<int, int> counter;
    for(int num: changed) counter[num]++;
    if(counter[0]%2 == 1) return {}; // edge case: odd number of 0s

    sort(changed.begin(), changed.end());

    vector<int> res;

    int toMapCount = changed.size()/2;
    for(int i = 0; i < changed.size(); i++) {
      int cur = changed[i];
      int doubleCur = 2*cur;

      if(counter.find(cur) == counter.end()) {
        // we don't have it anymore for use!
        continue;
      }

      // can we find double of cur?
      if(counter.find(doubleCur) != counter.end()) {
        // we use cur
        counter[cur]--;
        if(counter[cur] == 0) counter.erase(cur);
        // we use double cur
        counter[doubleCur]--;
        if(counter[doubleCur] == 0) counter.erase(doubleCur);

        res.push_back(cur);
        toMapCount--;
      }
    }

    return toMapCount == 0 ? res : vector<int>(); // could we map everything?
  }
};