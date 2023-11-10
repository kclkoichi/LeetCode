#include <string>
using namespace std;

class Solution {
public:
  int countTime(string time) {
    char hour1 = time[0];
    char hour2 = time[1];
    char min1 = time[3];
    char min2 = time[4];

    int possibilities = 1;

    if(hour2 == '?') {
      if(hour1 == '?') {
        possibilities*=24;
      } else if(hour1 == '0' || hour1 == '1') {
        possibilities*=10;
      } else {
        // hour2 == '2'
        possibilities*=4;
      }
    } else {
      // hour2 is fixed
      if(hour1 == '?') {
        if(hour2 < '4') {
          possibilities*=3;
        } else {
          possibilities*=2;
        }
      } else {
        // hour1 is also fixed
      }
    }

    if(min2 == '?') {
      if(min1 == '?') {
        possibilities*=60;
      } else {
        // min1 is fixed
        possibilities*=10;
      }
    } else {
      // min2 is fixed
      if(min1 == '?') {
        possibilities*=6;
      } else {
        // min1 is also fixed
      }
    }

    return possibilities;
  }
};