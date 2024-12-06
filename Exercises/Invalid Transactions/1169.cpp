#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string getName(string transaction) {
        string tmp;
        for(char c: transaction) {
            if(c == ',') {
                return tmp;
            } else {
                tmp += c;
            }
        }
        return "error";
    }

    int getTime(string transaction) {
        string tmp;
        int count = 0;
        for(char c: transaction) {
            if(c == ',') {
                if(count == 1) return stoi(tmp);
                tmp = "";
                count++;
            } else {
                tmp += c;
            }
        }
        return -1;
    }

    int getAmount(string transaction) {
        string tmp;
        int count = 0;
        for(char c: transaction) {
            if(c == ',') {
                if(count == 2) return stoi(tmp);
                tmp = "";
                count++;
            } else {
                tmp += c;
            }
        }
        return -1;
    }

    string getLocation(string transaction) {
        transaction += ","; // Won't ever get the location without this!!
        string tmp;
        int count = 0;
        for(char c: transaction) {
            if(c == ',') {
                if(count == 3) return tmp;
                tmp = "";
                count++;
            } else {
                tmp += c;
            }
        }
        return "error";
    }

    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<pair<int, string>> sortedTransactions;
        for(string transaction: transactions) {
            int time = getTime(transaction);
            sortedTransactions.push_back(make_pair(time, transaction));
        }
        sort(sortedTransactions.begin(), sortedTransactions.end());

        unordered_set<string> resSet;

        // Name -> Location -> [transaction]
        unordered_map<string, unordered_map<string, vector<string>>> nameToLocationToTransactions;
        for(pair<int, string> p: sortedTransactions) {
            string transaction = p.second;
            
            string name = getName(transaction);
            int time = getTime(transaction);
            int amount = getAmount(transaction);
            string location = getLocation(transaction);

            if(amount > 1000) {
                resSet.insert(transaction);
            }

            nameToLocationToTransactions[name][location].push_back(transaction);
            for(auto m: nameToLocationToTransactions[name]) {
                string curLocation = m.first;
                vector<string> transactionsAtLocation = m.second;

                if(location == curLocation) {
                    continue;
                }

                for(string curTransaction: transactionsAtLocation) {
                    int curTime = getTime(curTransaction);
                    if(time - curTime <= 60) {
                        resSet.insert(transaction);
                        resSet.insert(curTransaction);
                    }
                }
            }
        }

        vector<string> res;
        // for(string tr: resSet) res.push_back(tr);

        // Need to deal with duplicates in input list...
        for(auto a: nameToLocationToTransactions) {
            for(auto b: a.second) {
                for(string tr: b.second) {
                    if(resSet.find(tr) != resSet.end()) {
                        res.push_back(tr);
                    }
                }
            }
        }
        return res;
    }
};
