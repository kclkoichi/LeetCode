#include <list>
#include <set>
#include <unordered_map>
using namespace std;

class MaxStack {
public:
  list<int> stack; // maintain value, max at that time
  unordered_map<int, list<list<int>::iterator>> valueToPointer;
  multiset<int> BST;
  int max = INT_MIN;
  MaxStack() {}
  
  void push(int x) {
    if(x > max) max = x;
    BST.insert(x);
    stack.push_back(x);
    valueToPointer[x].push_back(--stack.end());
  }
  
  int pop() {
    int toReturn = stack.back();

    // remove from all data structures
    stack.pop_back();
    BST.erase(BST.find(toReturn));
    valueToPointer[toReturn].pop_back(); // remove latest pointer

    // update info about max
    if(stack.empty()) {
      max = INT_MIN;
    } else {
      max = stack.back();
    }
    return toReturn;
  }
  
  int top() {
    return stack.back();
  }
  
  int peekMax() {
    return *BST.rbegin();
  }
  
  int popMax() {
    int currentMax = *BST.rbegin();

    // remove from all data structures
    BST.erase(BST.find(currentMax));
    stack.erase(valueToPointer[currentMax].back()); // doing the popping in our stack
    valueToPointer[currentMax].pop_back();
    
    // update info about max
    if(stack.empty()) {
      max = INT_MIN;
    } else {
      max = stack.back();
    }
    return currentMax;
  }
};