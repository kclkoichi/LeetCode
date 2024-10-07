#include <unordered_map>
#include <vector>
using namespace std;

// Doing with diagonal
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
    for(auto mappingToB: counter) {
      for(auto bWithCount: mappingToB.second) {
        pair<int, int> p2 = make_pair(mappingToB.first, bWithCount.first);
        // check if it makes square
        pair<int, int> wanted1 = make_pair(p1.first, p2.second);
        pair<int, int> wanted2 = make_pair(p2.first, p1.second);
        if(!sameXaxis(p1, p2) && !sameYaxis(p1, p2) && sameWidthAndHeight(p1, p2)) {
          if(findPoint(wanted1) && findPoint(wanted2)) {
            countSquare += counter[p2.first][p2.second] * counter[wanted1.first][wanted1.second] * counter[wanted2.first][wanted2.second];
          }
        }
      }
    }
    return countSquare;
  }
  
  bool sameXaxis(pair<int, int> p1, pair<int, int> p2) {
    return p1.first == p2.first;
  }
  
  bool sameYaxis(pair<int, int> p1, pair<int, int> p2) {
    return p1.second == p2.second;
  }
  
  bool sameWidthAndHeight(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.second - p2.second) == abs(p1.first - p2.first);
  }

  bool findPoint(pair<int, int> p) {
    if(counter.find(p.first) != counter.end()){
      if(counter[p.first].find(p.second) != counter[p.first].end()){
        return true;
      }
    }
    return false;
  }
};
