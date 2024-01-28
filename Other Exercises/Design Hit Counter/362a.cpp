#include <unordered_map>
using namespace std;

class HitCounter {
public:
  unordered_map<int,int> counter;
  HitCounter() {}
  
  void hit(int timestamp) {
    counter[timestamp]++;
  }
  
  int getHits(int timestamp) {
    int count = 0;
    for(int i = timestamp-299; i <= timestamp; i++) {
      count+=counter[i];
    }
    return count;
  }
};
