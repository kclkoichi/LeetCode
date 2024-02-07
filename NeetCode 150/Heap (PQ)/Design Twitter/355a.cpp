#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Twitter {
public:
  int time = 1;
  unordered_map<int, unordered_set<int>> followingMap;
  // <time, tweetId>
  unordered_map<int, vector<pair<int, int>>> userTweetMap; // tweets are sorted ASC by time
  // We could only keep last 10 tweets of every user to save more space

  Twitter() {}
  
  void postTweet(int userId, int tweetId) {
    followingMap[userId].insert(userId); // every user follows themselves...
    userTweetMap[userId].push_back(make_pair(time, tweetId));
    time++;
  }
  
  vector<int> getNewsFeed(int userId) {
    auto cmp = [](pair<int, int> a, pair<int, int> b) {
      return a.first < b.first; // sorting by ASC time
    };
    // MAX heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    for(int followed: followingMap[userId]) {
      for(pair<int, int> tweet: userTweetMap[followed]) {
        pq.push(tweet);
      }
    }

    vector<int> res;
    int count = 1;
    while(!pq.empty() && count <= 10) {
      res.push_back(pq.top().second);
      pq.pop();
      count++;
    }
    return res;
  }
  
  void follow(int followerId, int followeeId) {
    followingMap[followerId].insert(followeeId);
  }
  
  void unfollow(int followerId, int followeeId) {
    followingMap[followerId].erase(followeeId);
  }
};