#include <vector>
#include <string>
using namespace std;

class Codec {
public:

  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    string encoded = "";
    for(string s : strs) {
      string cur = "";
      for(int i = 0; i < s.size(); i++) {
        if(s[i] == '#') cur+='#'; // ## in case of #
        cur+=s[i];
      }
      encoded += (cur+"#,"); // #, is delimiter
    }
    return encoded;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> decoded;
    string cur = "";
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == '#') {
        if(s[i+1] == '#') {
          cur += '#';
          i++;
        } else {
          decoded.push_back(cur);
          cur = "";
          i++;
        }
      } else {
        cur+=s[i];
      }
    }
    return decoded;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));