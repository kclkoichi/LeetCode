// implement a set collection without using any built in hashtable etc
// want set support
// - add(int val)
// - contains(int val)
// - remove(int val)

// constraints:
// okay to store int [0..1000000]

#include <vector>
#include <list>
using namespace std;

class Storer {
  public:
  vector<bool> container;
  list<int> l;

  Storer() {
    container = vector<bool>(1000001);
  }

  void add(int i) {
    container[i] = true;
    l.push_back(i);
  }

  void remove(int i) {
    container[i] = false;
  }

  bool contains(int i) {
    return container[i];
  }

  // list return all values to the set
  list<int> listInteger() {
    list<int> ret;
    for(int i : l) {
      if(container[i]) ret.push_back(i);
    }
    return ret;
  }
};