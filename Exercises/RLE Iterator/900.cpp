#include <vector>
using namespace std;

class RLEIterator {
public:
  int i = 0;
  vector<int> encodedVector;
  RLEIterator(vector<int>& encoding) {
    encodedVector = encoding;
  }
  
  int next(int n) {
    if(i >= encodedVector.size()) return -1; // exhausted!
    int curRemaining = encodedVector[i] - n;
    while(curRemaining < 0) {
      n = -curRemaining;
      i+=2;
      if(i >= encodedVector.size()) return -1; // exhausted!
      curRemaining = encodedVector[i] - n;
    }
    encodedVector[i] = curRemaining;
    return encodedVector[i+1];
  }
};
