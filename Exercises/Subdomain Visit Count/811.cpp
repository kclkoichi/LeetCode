#include <vector>
#include <string>
#include <unordered_map>
#include <list>
using namespace std;

class Solution {
public:
  vector<string> cut(string domain) {
    list<char> cur;
    vector<string> ret;
    for(int i = domain.size() - 1; i >= 0; i--) {
      if(domain[i] == '.') {
        string toAdd = "";
        for(char c : cur) {
          toAdd += c;
        }
        ret.push_back(toAdd);
        cur.push_front(domain[i]);
      } else {
        cur.push_front(domain[i]);
      }
    }
    // last str
    string toAdd = "";
    for(char c : cur) {
      toAdd += c;
    }
    ret.push_back(toAdd);
    return ret;
  }

  vector<string> subdomainVisits(vector<string>& cpdomains) {
    unordered_map<string, int> counter;
    for(string domain: cpdomains) {
      int i = 0;
      string numStr = "";
      while(i < domain.size()) {
        if(domain[i] == ' ') break;
        numStr += domain[i];
        i++;
      }
      int num = stoi(numStr);
      i++;

      string toCut = domain.substr(i, domain.size() - i);
      vector<string> subdomains = cut(toCut);
      for(string subdomain: subdomains) {
        counter[subdomain] += num;
      }
    }

    vector<string> res;
    for(auto a : counter) {
      res.push_back(to_string(a.second) + " " + a.first);
    }
    return res;
  }
};