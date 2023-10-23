#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
public:
  int maxCapacity = 0;
  unordered_map<int, int> keyValueMap;
  unordered_map<int, int> keyCountMap;

  unordered_map<int, list<int>> countListMap;
  unordered_map<int, list<int>::iterator> keyIteratorMap;

  int elementCount = 0;
  int minCount = 0;

  LFUCache(int capacity) {
    maxCapacity = capacity;
  }

  void update(int key) {
    // Erase from old count list
    int oldCount = keyCountMap[key];
    countListMap[oldCount].erase(keyIteratorMap[key]);

    // minCount = countListMap[oldCount].size() == 0 ? oldCount+1 : oldCount; // THE UPDATED OLDCOUNT MIGHT NOT BE MINCOUNT!!!
    // Update the min count (freq) of LFU cache ONLY IF THE CURRENTLY UPDATED KEY IS MINCOUNT!!
    if(countListMap[minCount].size() == 0) {
      minCount++;
    }

    // Update frequency of use
    keyCountMap[key]++;
    int newCount = keyCountMap[key];

    // Update new count list, and pointer to just newly inserted key in list
    countListMap[newCount].push_front(key);
    keyIteratorMap[key] = countListMap[newCount].begin();
  }
  
  int get(int key) {
    if(keyValueMap.find(key) == keyValueMap.end()) return -1;
    update(key);
    return keyValueMap[key];
  }
  
  void put(int key, int value) {
    if(keyValueMap.find(key) != keyValueMap.end()) {
      // Update value of key
      keyValueMap[key] = value;
      update(key);
    } else {
      // New key

      if(elementCount == maxCapacity) {
        // Remove LFU key from LFU count list
        int LFUkey = countListMap[minCount].back(); // We remove LRU from the list!! Which is the back of the list as we insert new at front
        countListMap[minCount].pop_back(); // No worries for minCount, it will become 1 as we insert new key

        // Remove from all hashmap maintaining data about LFU key
        keyValueMap.erase(keyValueMap.find(LFUkey));
        keyCountMap.erase(keyCountMap.find(LFUkey));
        keyIteratorMap.erase(keyIteratorMap.find(LFUkey));
      } else {
        elementCount++;
      }

      // Add new element to LFU cache
      keyValueMap[key] = value;
      keyCountMap[key] = 1;
      countListMap[1].push_front(key);
      keyIteratorMap[key] = countListMap[1].begin();

      minCount = 1; // As newly inserted key has frequency 1
    }
  }
};

class LFUCache2 {
public:
  int maxCapacity;
  int elementCount;
  int minCount;
  unordered_map<int, int> keyValueMap;
  unordered_map<int, int> keyCountMap;
  unordered_map<int, list<int>> countListMap;
  unordered_map<int, list<int>::iterator> keyIteratorMap;

  LFUCache2(int capacity) {
    maxCapacity = capacity;
    elementCount = 0;
    minCount = 0;
  }

  void update(int key) {
    int count = keyCountMap[key];
    auto it = keyIteratorMap[key];
    keyCountMap[key]++;
    countListMap[count].erase(it);
    countListMap[count+1].push_back(key);
    keyIteratorMap[key] = --countListMap[count+1].end();
    if(countListMap[minCount].empty()) minCount++;
  }

  int get(int key) {
    if (keyValueMap.find(key) == keyValueMap.end()) return -1;
    update(key);
    return keyValueMap[key];
  }

  void put(int key, int value) {
    if (keyValueMap.find(key) != keyValueMap.end()) {
      keyValueMap[key] = value;
      update(key);
    } else {
      if (elementCount == maxCapacity) {
        int LFUkey = countListMap[minCount].front();
        countListMap[minCount].pop_front();
        keyValueMap.erase(LFUkey);
        keyCountMap.erase(LFUkey);
        keyIteratorMap.erase(LFUkey);
      } else { 
        elementCount++;
      }

      keyValueMap[key] = value;
      keyCountMap[key] = 1;
      countListMap[1].push_back(key);
      keyIteratorMap[key] = --countListMap[1].end();
      minCount = 1;
    }
  }
};

class LFUCache3 {
public:
  int maxCapacity;
  int elementCount;
  int minCount;
  unordered_map<int, int> keyValueMap;
  unordered_map<int, int> keyCountMap;
  unordered_map<int, list<int>> countListMap;
  unordered_map<int, list<int>::iterator> keyIteratorMap;
  
  LFUCache3(int capacity) {
    maxCapacity = capacity;
    elementCount = 0;
    minCount = 0;
  }

  void update(int key) {
    int freq = keyCountMap[key];
    auto iter = keyIteratorMap[key];
    keyCountMap[key]++;
    countListMap[freq].erase(iter);
    countListMap[freq + 1].push_back(key);
    keyIteratorMap[key] = --countListMap[freq + 1].end();
    if (countListMap[minCount].empty()) {
      minCount++;
    }
  }
  
  int get(int key) {
    if (keyValueMap.find(key) == keyValueMap.end()) {
      return -1;
    }
    update(key);
    return keyValueMap[key];
  }
  
  void put(int key, int value) {
    if (keyValueMap.find(key) != keyValueMap.end()) {
      keyValueMap[key] = value;
      update(key);
    } else {
      if (elementCount == maxCapacity) {
        int evict = countListMap[minCount].front();
        countListMap[minCount].pop_front();
        keyValueMap.erase(evict);
        keyCountMap.erase(evict);
        keyIteratorMap.erase(evict);
      } else {
        elementCount++;
      }
      keyValueMap[key] = value;
      keyCountMap[key] = 1;
      countListMap[1].push_back(key);
      keyIteratorMap[key] = --countListMap[1].end();
      minCount = 1;
    }
  }
};