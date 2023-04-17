#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
public:
  unordered_map<int, list<int>::iterator> pointer_map;
  unordered_map<int, int> value_map;
  // Most recently used is front, least recently used is tail
  list<int> queue;
  int max_size;
  int size;

  LRUCache(int capacity) {
    max_size = capacity;
    size = 0;
  }

  void updateMostRecentlyUsed(int key) {
    queue.erase(pointer_map.find(key)->second);
    queue.push_front(key); // 
    pointer_map[key] = queue.begin();
  }
  
  int get(int key) {
    // Check if exists
    if(pointer_map.find(key) == pointer_map.end()) return -1;
    // Update position
    updateMostRecentlyUsed(key);
    return value_map[key];
  }
  
  void put(int key, int value) {
    // If key exists, update value
    if(pointer_map.find(key) != pointer_map.end()) {
      updateMostRecentlyUsed(key);
      value_map[key] = value;
      return;
    }

    // We add a new key-value pair
    // If cache is full, remove LRU pair
    if(size == max_size) {
      int removeKey = queue.back();
      queue.erase(pointer_map.find(removeKey)->second);
      pointer_map.erase(pointer_map.find(removeKey));
      value_map.erase(value_map.find(removeKey));
      size--;
    }
    // Add to queue
    queue.push_front(key);
    pointer_map[key] = queue.begin();
    value_map[key] = value;
    size++;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */