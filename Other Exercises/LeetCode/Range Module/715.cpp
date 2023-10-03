#include <set>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// default fake values
vector<int> insideV{-1, -1};
vector<int> intersectV{-1, -1};
vector<int> inserted{-2, -2};

class RangeModule {
public:
  static bool inside(const vector<int>& a, const vector<int>& b) {
    return a[0] >= b[0] && a[1] <= b[1];
  }

  static bool intersect(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[1] && a[1] > b[0];
  }

  // invalidate, because we don't want old data for it to be used
  void reset() {
    intersectV = {-1, -1};
    insideV = {-1, -1};
    inserted = {-2, -2};
  }

  function<bool(const vector<int>&, const vector<int>&)> cmp = [](const vector<int>& a, const vector<int>& b) {
    // the one getting inserted is b
    if(b == inserted) {
      if(inside(b, a)) {
        insideV = a;
      } else if(intersect(a, b)) {
        intersectV = b;
      }
    }
    if(a[0] == b[0]) return a[1] > b[1];
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

    inserted = toAdd;
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
    reset();
  }
  
  bool queryRange(int left, int right) {
    if(s.size() == 0) return false;
    inserted = {left, right};
    s.find({left, right}); // to trigger inside
    bool ret = inside({left, right}, insideV);
    reset();
    return ret;
  }
  
  void removeRange(int left, int right) {
    if(s.size() == 0) return;
    vector<int> toRemove { left, right };
    inserted = {left, right};
    s.find(toRemove); // to trigger intersect and inside
    if(inside(toRemove, insideV)) {
      vector<int> original = insideV;
      s.insert({ original[0], toRemove[0]} );
      s.insert({ toRemove[1], original[1]} );
      s.erase(original);
    } else if(intersect(toRemove, intersectV)) {
      if(intersectV[1] > toRemove[0]) {
        intersectV[1] = toRemove[0];
      } else {
        intersectV[0] = toRemove[1];
      }
    }
    reset();
  }
};

// vector<int> a = vector<int>();
// vector<int>& RangeModule::insideV = a;
// vector<int> b = vector<int>();
// vector<int>& RangeModule::intersectV = b;

int main() {
  RangeModule* obj = new RangeModule();
  obj->addRange(1,10);
  obj->removeRange(4,6);
  cout << obj->queryRange(1,5) << endl;
  cout << obj->queryRange(1,6) << endl;
  cout << obj->queryRange(1,7) << endl;
  cout << obj->queryRange(4,5) << endl;
  cout << obj->queryRange(4,6) << endl;
  cout << obj->queryRange(4,7) << endl;
  cout << obj->queryRange(6,7) << endl;
  return 0;
}

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */