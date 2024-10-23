#include <string>
using namespace std;

class Solution {
public:
  bool validWordAbbreviation(string word, string abbr) {
    int wordIndex = 0;
    for(int i = 0; i < abbr.size(); i++) {
      if(abbr[i] >= 'a' && abbr[i] <= 'z') {
        if(abbr[i] != word[wordIndex]) {
          return false;
        }
        wordIndex++;
      } else {
        // it's a number
        string number = "";
        while(i < abbr.size() && abbr[i] >= '0' && abbr[i] <= '9') {
          number += abbr[i];
          i++;
        }
        if(number[0] == '0') return false; // no leading 0s/0 for abbreviation
        wordIndex += stoi(number);
        i--;
      }
    }

    return wordIndex == word.size();
  }
};
