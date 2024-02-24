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
  string lastNonEmptyString(string s) {
    vector<int> count(26);
    for(char c: s) count[c - 'a']++;
    int maxOccurence = 0;
    for(int c: count) maxOccurence = max(maxOccurence, c);
    string res;
    unordered_set<char> have;
    for(char c: s) {
      if(count[c - 'a'] == maxOccurence) {
        have.insert(c);
      }
    }
    for(char c: s) {
      if(have.find(c) != have.end()) {
        count[c - 'a']--;
        if(count[c - 'a'] == 0) res.push_back(c);
      }
    }
    return res;
  }
};