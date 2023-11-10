#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
  // TLE
  // I would say:
  // Time: O(jug1Capacity+1 * jug2Capacity+1) because that's the maximum number of states without mathemtical approach
  // Space: O(jug1Capacity+1 * jug2Capacity+1) because max states in queue...
  bool canMeasureWaterBFS(int jug1Capacity, int jug2Capacity, int targetCapacity) {
    if(targetCapacity % 2 == 1 && jug1Capacity % 2 == 0 && jug2Capacity % 2 == 0) return false;

    // jug1 content, jug2 content
    unordered_map<int, unordered_set<int>> memo;

    queue<vector<int>> states;
    // Original jug1 content, jug2 content
    states.push({ 0, 0 });

    while(!states.empty()) {
      vector<int> cur = states.front();
      states.pop();

      int jug1 = cur[0];
      int jug2 = cur[1];
      if(jug1 + jug2 == targetCapacity) return true;
      if(memo[jug1].find(jug2) != memo[jug1].end()) continue; // we've already been in this state
      memo[jug1].insert(jug2);

      // Fill jug 1
      states.push({jug1Capacity, jug2});
      // Fill jug 2
      states.push({jug1, jug2Capacity});
      // Transfer jug1 to jug2
      states.push({max(0, jug1 - (jug2Capacity - jug2)), min(jug2 + jug1, jug2Capacity)});
      // Transfer jug2 to jug1
      states.push({min(jug1 + jug2, jug1Capacity), max(0, jug2 - (jug1Capacity - jug1))});
      // Throw away jug1
      states.push({0, jug2});
      // Throw away jug2
      states.push({jug1, 0});
    }

    return false;
  }

  bool canMeasureWater(int x, int y, int z) {
    return z == 0 || z <= (long long)x + y && z % __gcd(x, y) == 0;
  }
};
