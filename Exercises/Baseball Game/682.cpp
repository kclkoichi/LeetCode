#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> res;
        for(string op: operations) {
            if(op == "+") {
                res.push_back(res[res.size()-1] + res[res.size()-2]);
            } else if(op == "D") {
                res.push_back(2 * res[res.size()-1]);
            } else if(op == "C") {
                res.pop_back();
            } else {
                int num = stoi(op);
                res.push_back(num);
            }
        }

        int rres = 0;
        for(int i: res) rres += i;
        return rres;
    }
};
