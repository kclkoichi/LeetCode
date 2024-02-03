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
  int numberOfPairs(vector<vector<int>>& points) {
    int count = 0;

    for(int i = 0; i < points.size() - 1; i++) {
      for(int j = i+1; j < points.size(); j++) {
        // i, j
        vector<int> chisato = points[i];
        vector<int> takina = points[j];
        if(chisato[0] > takina[0] || chisato[1] < takina[1]) {
          // chisato is more right than takina! ||
          // chisato is lower than takina!
        } else {
          bool possible = true;
          for(int k = 0; k < points.size(); k++) {
            if(k == i || k == j) continue;
            vector<int> person = points[k];
            if(person[0] >= chisato[0] && person[0] <= takina[0]) {
              if(person[1] <= chisato[1] && person[1] >= takina[1]) {
                possible = false;
                break;
              }
            }
          }
          if(possible) count++;
        }

        // j, i
        chisato = points[j];
        takina = points[i];
        if(chisato[0] > takina[0] || chisato[1] < takina[1]) {
          // chisato is more right than takina! ||
          // chisato is lower than takina!
        } else {
          bool possible = true;
          for(int k = 0; k < points.size(); k++) {
            if(k == i || k == j) continue;
            vector<int> person = points[k];
            if(person[0] >= chisato[0] && person[0] <= takina[0]) {
              if(person[1] <= chisato[1] && person[1] >= takina[1]) {
                possible = false;
                break;
              }
            }
          }
          if(possible) count++;
        }
      }
    }

    return count;
  }
};