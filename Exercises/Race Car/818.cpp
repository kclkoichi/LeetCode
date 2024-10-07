#include <vector>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;

class Solution {
public:
  // time complexity: O(log t) with t target because we power two each time to accelerate
  // space complexity: O(log t)
  int racecar(int target) {
    // moves, speed, position
    queue<tuple<int, ll, ll>> q = queue<tuple<int, ll, ll>>();
    unordered_map<ll, unordered_set<ll>> visited = unordered_map<ll, unordered_set<ll>>();
    q.push(make_tuple(0, 1, 0));
    while(!q.empty()) {
      int moves = get<0>(q.front());
      ll speed = get<1>(q.front());
      ll position = get<2>(q.front());
      q.pop();

      if(visited[position].find(speed) != visited[position].end()) continue;
      visited[position].insert(speed);

      if(position == target) return moves;
      q.push(make_tuple(moves+1, speed*2, position+speed));
      if((position+speed > target && speed > 0) || (position+speed < target && speed < 0)) {
        speed = speed < 0 ? 1 : -1;
        q.push(make_tuple(moves+1, speed, position));
      }
    }

    return -1;
  }
};

int main() {
  Solution s;
  s.racecar(5);
  return 0;
}