#include <vector>
#include <string>
#include <list>
using namespace std;

class Solution {
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    // Create list of strings, one list = one line. int is size of string
    vector<pair<list<string>, int>> lines = vector<pair<list<string>, int>>(1);
    int cur = 0;
    int i = 0;
    for(string word : words) {
      // if we can't add word anymore
      if(cur+word.size() > maxWidth) {
        // if have more than one word and one space
        if(lines[i].first.size() > 2) {
          lines[i].first.pop_back(); // get rid of last space;
          lines[i].second = cur - 1; // size of string (without last space)
        } else {
          // if the single word size is == maxwidth, remove space
          if(lines[i].first.front().size() == maxWidth) {
            lines[i].first.pop_back(); // get rid of last space;
            lines[i].second = cur - 1; // size of string (without last space)
          } else {
            lines[i].second = cur; // keep last space for single word (otherwise we can't add spaces)
          }
        }

        lines.push_back(make_pair(list<string>(), 0)); // create next list
        i++;
        cur = 0;
      }
      cur += word.size() + 1;
      lines[i].first.emplace_back(word);
      lines[i].first.emplace_back(" ");
    }

    // last line is lacking .second
    lines[i].first.pop_back();
    lines[i].second = cur - 1;

    // add spaces
    for(int j = 0; j < lines.size(); j++) {
      // references
      list<string>& line = lines[j].first;
      int& count = lines[j].second;

      // last line is special
      if(j == lines.size() - 1) {
        while(count < maxWidth) {
          line.insert(line.end(), " ");
          count++;
        }
        break;
      }

      // get list of pointers to spaces
      vector<list<string>::iterator> positions;
      for(auto it = line.begin(); it != line.end(); ++it) {
        if((*it) == " ") positions.push_back(it);
      }

      // add more spaces
      while(count < maxWidth) {
        for(auto it : positions) {
          line.insert(it, " ");
          count++;
          if(count >= maxWidth) break;
        }
      }
    }

    // make strings
    vector<string> res;
    for(auto p : lines) {
      list<string> line = p.first;
      string cur = "";
      for(string s : line) {
        cur += s;
      }
      res.push_back(cur);
    }
    return res;
  }
};