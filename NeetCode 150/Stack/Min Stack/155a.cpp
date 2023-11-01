#include <vector>
using namespace std;

class MinStack {
public:
  int min = INT_MAX;
  vector<pair<int,int>> stack; // pair of value and min at that time
  MinStack() {}
  
  void push(int val) {
    if(val < min) {
      min = val;
    }
    stack.push_back(make_pair(val, min));
  }
  
  void pop() {
    stack.pop_back();
    if(stack.empty()) {
      min = INT_MAX; // need to reset min as there is no value anymore
    } else {
      min = getMin(); // min might be updated
    }
  }
  
  int top() {
    return stack[stack.size() - 1].first;
  }
  
  int getMin() {
    return stack[stack.size() - 1].second;
  }
};