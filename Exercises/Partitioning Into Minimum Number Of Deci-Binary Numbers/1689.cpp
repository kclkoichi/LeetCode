#include <string>
using namespace std;

class Solution {
public:
  int minPartitions(string n) {
    char biggest = (char)0;
    for(char c : n) if(c > biggest) biggest = c;
    return biggest - '0';
  }
};