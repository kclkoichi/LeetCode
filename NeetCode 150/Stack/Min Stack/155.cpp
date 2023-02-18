#include <math.h>
#include <list>
using namespace std;

#include <math.h>
#include <list>
using namespace std;

class MinStack {
public:
  list<pair<int, int>> store;
  int min = INT_MAX;

  MinStack() {
    store = list<pair<int, int>>();
  }
  
  void push(int val) {
    if(val < min) min = val;
    store.emplace_front(pair(val, min));
  }
  
  void pop() {
    store.erase(store.begin());
    if(store.empty()) {
        min = INT_MAX;
    } else {
        min = store.begin()->second;
    }
  }
  
  int top() {
    return store.begin()->first;
  }
  
  int getMin() {
    return store.begin()->second;
  }
};

// LeetCode
int main() {
  MinStack s = MinStack();
  s.push(-10);
  s.push(14);
  s.getMin();
  s.getMin();
  s.push(-20);
  s.getMin();
  s.getMin();
  s.top();
  s.getMin();
  s.pop();
  s.push(10);
  s.push(-7);
  s.getMin();
  s.push(-7);
  s.pop();
  s.top();
  s.getMin();
  s.pop();

  return 0;
}