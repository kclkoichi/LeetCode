#include <iostream>
#include <math.h>
#include <algorithm> // max
#include <string>
#include <algorithm> // sort, stable_sort

#include <vector>
#include <list>
#include <stack>
#include <queue> // and MAX priority queue
#include <deque>

#include <set> // BBST (and multiset)
#include <map> // BBST (and multimap)
#include <unordered_set> // Hash Table, boolean
#include <unordered_map> // Hash Table, map to something
using namespace std;

typedef long long ll;

class Solution {
public:
  vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    int res1 = 0;
    unordered_set<int> numbers1;
    for(int i: nums1) numbers1.insert(i);
    for(int i: nums2) {
      if(numbers1.find(i) != numbers1.end()) res1++;
    }

    int res2 = 0;
    unordered_set<int> numbers2;
    for(int i: nums2) numbers2.insert(i);
    for(int i: nums1) {
      if(numbers2.find(i) != numbers2.end()) res2++;
    }

    return {res2, res1};
  }
};