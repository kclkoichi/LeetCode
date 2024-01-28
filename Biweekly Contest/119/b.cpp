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
  bool adjacent(char a, char b) {
    return a == b || a-1 == b || a+1 == b;
  }

  int removeAlmostEqualCharacters(string word) {
    int count = 0;
    for(int i = 1; i < word.size(); i++) {
     if(adjacent(word[i-1], word[i])) {
        count++;
        i++;
      }
    }
    return count;
  }
};
