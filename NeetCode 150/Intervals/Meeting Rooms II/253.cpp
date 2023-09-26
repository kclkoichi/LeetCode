#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    auto cmp = [](pair<int, char> a, pair<int, char> b){
      if(a.first == b.first) return a.second < b.second; // We want 'e'nd before 's'tart
      return a.first < b.first; // asc, time 
    };

    multiset<pair<int, char>, decltype(cmp)> timeline;

    for(vector<int> booking: intervals) {
      timeline.insert(make_pair(booking[0], 's'));
      timeline.insert(make_pair(booking[1], 'e'));
    }

    int maxStart = 0;
    int startCount = 0;

    auto it = timeline.begin();
    while(it != timeline.end()) {
      switch((*it).second) {
        case 's':
          startCount++;
          if(startCount > maxStart) maxStart = startCount;
          break;
        case 'e':
          startCount--;
          break;
      }
      it++;
    }
 
    return maxStart;
  }
};