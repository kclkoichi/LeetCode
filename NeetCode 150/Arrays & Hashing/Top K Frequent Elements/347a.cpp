#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
using namespace std;

// Time complexity O(n log n) using hashmap and heap
class Solution {
public:
  vector<int> topKFrequent2(vector<int>& nums, int k) {
    unordered_map<int, int> numToCount;
    for(int num: nums) {
      numToCount[num]++;
    }

    auto cmp = [](pair<int,int> a, pair<int,int> b) {
      return a.second < b.second; // compares based on second value
    };

    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> maxHeap(cmp);

    for(auto [num, count]: numToCount) {
      maxHeap.push(make_pair(num, count));
    }

    vector<int> res;
    for(int i = 1; i <= k; i++) {
      res.push_back(maxHeap.top().first);
      maxHeap.pop();
    }
    return res;
  }

  // O(n) bucket sort solution using hashmap and vector of list
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> numToCount;
    for(int num: nums) numToCount[num]++;

    vector<list<int>> bucket = vector<list<int>>(nums.size()+1);
    for(auto [num, count]: numToCount) bucket[count].push_back(num);

    vector<int> res;
    for(int i = nums.size(); i >= 0; i--) {
      for(int num: bucket[i]) {
        res.push_back(num);
        if(res.size() == k) return res;
      }
      if(res.size() == k) return res;
    }
    return res;
  }
};