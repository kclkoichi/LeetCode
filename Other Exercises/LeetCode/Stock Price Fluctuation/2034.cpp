#include <map>
#include <set>
using namespace std;

class StockPrice {
public:
  multiset<int> counts;
  map<int, int> m; // timestamp, price
  vector<int> latest {-1, -1};

  StockPrice() {}
  
  void update(int timestamp, int price) {
    if(latest[0] <= timestamp) latest = {timestamp, price};
    if(m.find(timestamp) != m.end()) {
      counts.erase(counts.find(m[timestamp]));
    }
    m[timestamp] = price;
    counts.insert(price);
  }
  
  int current() {
    return latest[1];
  }
  
  int maximum() {
    return *(counts.rbegin());
  }
  
  int minimum() {
    return *(counts.begin());
  }
};