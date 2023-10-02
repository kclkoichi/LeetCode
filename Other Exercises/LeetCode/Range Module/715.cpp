#include <set>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class RangeModule {
public:
  static bool inside(const vector<int>& a, const vector<int>& b) {
    return a[0] >= b[0] && a[1] < b[1];
  }
  static vector<int>& insideV;

  static bool intersect(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[1] && a[1] > b[0];
  }
  static vector<int>& intersectV;

  function<bool(const vector<int>&, const vector<int>&)> cmp = [](const vector<int>& a, const vector<int>& b) {
    if(inside(a, b)) {
      insideV = b;
    } else if(intersect(a, b)) {
      intersectV = b;
    }
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
  };

  set<vector<int>, decltype(cmp)> s;

  RangeModule() {
    s = set<vector<int>, decltype(cmp)>(cmp);
  }
  
  void addRange(int left, int right) {
    vector<int> toAdd { left, right };
    if(s.size() == 0) {
      s.insert(toAdd); 
      return;
    }

    s.find(toAdd); // to trigger intersect
    if(intersect(toAdd, intersectV)) {
      if(intersectV[1] < toAdd[1]) {
        intersectV[1] = toAdd[1];
      } else {
        intersectV[0] = toAdd[0];
      }
    } else {
      s.insert(toAdd);
    }
  }
  
  bool queryRange(int left, int right) {
    if(s.size() == 0) return false;
    s.find({left, right}); // to trigger inside
    return inside({left, right}, insideV);
  }
  
  void removeRange(int left, int right) {
    if(s.size() == 0) return;
    vector<int> toRemove { left, right };
    s.find(toRemove); // to trigger intersect and inside
    if(inside(toRemove, insideV)) {
      s.insert({ insideV[0], toRemove[0]} );
      s.insert({ toRemove[1], insideV[1]} );
      s.erase(toRemove);
    } else if(intersect(toRemove, intersectV)) {
      if(intersectV[1] > toRemove[0]) {
        intersectV[1] = toRemove[0];
      } else {
        intersectV[0] = toRemove[1];
      }
    }

  }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */