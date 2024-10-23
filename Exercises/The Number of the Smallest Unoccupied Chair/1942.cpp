#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Making it a min pq, pq is max pq by default
// You want leaving to have priority over arriving
// operator returns true when p1 is smaller than p2?
class Compare {
  public:
    bool operator() (pair<int, pair<char, int>> p1, pair<int, pair<char, int>> p2) {
      if(p1.first == p2.first) {
        return p1.second.first == 'a';
      }
      return p1.first > p2.first;
    }
};

class Solution {
public:
  int smallestChair(vector<vector<int>>& times, int targetFriend) {
    priority_queue<pair<int, pair<char, int>>, vector<pair<int, pair<char, int>>>, Compare> pq;
    for(int i = 0; i < times.size(); i++) {
      // time, arriving/leaving, friend index
      pq.push(make_pair(times[i][0], make_pair('a', i))); // arriving
      pq.push(make_pair(times[i][1], make_pair('l', i))); // leaving
    }

    unordered_map<int, int> m; // friend to seat
    priority_queue<int> chairs; // index of chair

    int cur = 0;
    while(!pq.empty()) {
      int time = pq.top().first;
      char command = pq.top().second.first;
      int curFriend = pq.top().second.second;
      pq.pop();
      if(command == 'a') {
        if(chairs.size() > 0) {
          m[curFriend] = -chairs.top(); // we want min pq
          chairs.pop();
        } else {
          m[curFriend] = cur;
          cur++;
        }
      } else {
        chairs.push(-m[curFriend]); // we want min pq
      }
    }

    return m[targetFriend];
  }
};
