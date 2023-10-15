#include <queue>
using namespace std;

class HitCounter {
public:
  // This works because new timestamps are always given >= to current timestamp
  queue<int> q;
  HitCounter() {}
  
  void hit(int timestamp) {
    q.push(timestamp);
  }
  
  int getHits(int timestamp) {
    while(!q.empty() && q.front() <= timestamp - 300) {
      q.pop();
    }
    return q.size();
  }
};