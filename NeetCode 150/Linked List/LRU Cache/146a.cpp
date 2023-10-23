#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
public:
  int max;
  list<int> ordering; // front == most recent, back == oldest
  unordered_map<int, int> keyValueMap;
  unordered_map<int, list<int>::iterator> keyPointerMap;

  LRUCache(int capacity) {
    max = capacity;
  }

  // key must exist
  void erase(int key) {
    ordering.erase(keyPointerMap[key]);
    keyValueMap.erase(keyValueMap.find(key));
    keyPointerMap.erase(keyPointerMap.find(key));
  }

  // key must exist
  void setMostRecentlyUsed(int key) {
    // Delete key in queue
    ordering.erase(keyPointerMap[key]);

    // Push key to front of ordering because newest
    ordering.push_front(key);

    // Refresh pointer (create or update)
    keyPointerMap[key] = ordering.begin();
  }
  
  int get(int key) {
    if(keyValueMap.find(key) == keyValueMap.end()) return -1; // not found
    setMostRecentlyUsed(key);
    return keyValueMap[key];
  }
  
  void put(int key, int value) {
    if(keyValueMap.find(key) != keyValueMap.end()) {
      setMostRecentlyUsed(key);
      keyValueMap[key] = value;
    } else {
      if(ordering.size() == max) erase(ordering.back());
      ordering.push_front(key);
      keyValueMap[key] = value;
      keyPointerMap[key] = ordering.begin();
    }
  }
};