#include <unordered_map>
#include <vector>
using namespace std;

class DetectSquares {
public:
  unordered_map<int, unordered_map<int, int>> counter;

  DetectSquares() {
    counter = unordered_map<int, unordered_map<int, int>>();
  }
  
  void add(vector<int> point) {
    counter[point[0]][point[1]]++;
  }
  
  int count(vector<int> point) {
    pair<int, int> p1 = make_pair(point[0], point[1]);
    int countSquare = 0;

    // For every added point p2
    for(auto mappingToB: counter) {
      for(auto bWithCount: mappingToB.second) {
        pair<int, int> p2 = make_pair(mappingToB.first, bWithCount.first);
        // If p1 and p2 same Y
        if(p1.second == p2.second) {
          // If they're not same points
          if(p1.first != p2.first) {
            // Get width
            int width = abs(p1.first - p2.first);
            // Consider UP case
            pair<int, int> wantedUp1 = make_pair(p1.first, p1.second + width);
            pair<int, int> wantedUp2 = make_pair(p2.first, p2.second + width);
            if(findPoint(wantedUp1) && findPoint(wantedUp2)) {
              countSquare += countPatterns(p2, wantedUp1, wantedUp2);
            }
            // Consider DOWN case
            pair<int, int> wantedDown1 = make_pair(p1.first, p1.second - width);
            pair<int, int> wantedDown2 = make_pair(p2.first, p2.second - width);
            if(findPoint(wantedDown1) && findPoint(wantedDown2)) {
              countSquare += countPatterns(p2, wantedDown1, wantedDown2);
            }
          }
        }
      }
    }
    return countSquare;
  }

  bool findPoint(pair<int, int> p) {
    if(counter.find(p.first) != counter.end()){
      if(counter[p.first].find(p.second) != counter[p.first].end()){
        return true;
      }
    }
    return false;
  }

  int countPatterns(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    return counter[p1.first][p1.second] * counter[p2.first][p2.second] * counter[p3.first][p3.second];
  }
};
