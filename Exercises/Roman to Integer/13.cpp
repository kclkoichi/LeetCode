#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    unordered_map<char, int> mapping = unordered_map<char, int>();
    mapping['I'] = 1;
    mapping['V'] = 5;
    mapping['X'] = 10;
    mapping['L'] = 50;
    mapping['C'] = 100;
    mapping['D'] = 500;
    mapping['M'] = 1000;

    int sum = 0;
    char prev = ' ';
    for(int i = 0; i < s.size(); i++) {
      int cur = mapping[s[i]];
      int next = mapping[s[i+1]];
      if(i == s.size() - 1) {
        sum += cur;
      } else if(next > cur) {
        sum += (next - cur);
        i++; // skip next
      } else {
        sum += cur;
      }
    }
    return sum;
  }
};