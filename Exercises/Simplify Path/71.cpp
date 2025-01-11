#include <string>
#include <deque>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> q;
        string cur;
        path.push_back('/'); // To force last dir to be processed
        for(int i = 0; i < path.size(); i++) {
            if(path[i] == '/') {
                if(cur.empty()) continue;
                if(cur == ".") {
                    // Do nothing
                } else if(cur == "..") {
                    if(q.size() > 0) q.pop_back();
                } else {
                    q.push_back(cur);
                }
                cur = "";
            } else {
                cur += path[i];
            }
        }

        string res;
        for(string s: q) res += "/" + s;
        if(res.empty()) res.push_back('/');
        return res;
    }
};
