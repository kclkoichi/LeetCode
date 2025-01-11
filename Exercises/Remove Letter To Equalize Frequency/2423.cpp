#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> counter(26);
        for(char c: word) counter[c - 'a']++;

        for(int i = 0; i < counter.size(); i++) {
            if(counter[i] == 0) continue;
            counter[i]--;
            int toCheck = -1;
            bool allSame = true;
            for(int j: counter) {
                if(j == 0) continue;
                if(toCheck == -1) toCheck = j;
                if(j != toCheck) {
                    allSame = false;
                    break;
                }
            }
            if(allSame) return true;
            counter[i]++;
        }

        return false;
    }
};
