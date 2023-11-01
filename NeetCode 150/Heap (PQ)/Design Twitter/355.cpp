#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

class Twitter {
public:
  int currentTime = -1;
  unordered_map<int, unordered_set<int>> followMap;
  vector<pair<int,int>> timeToTweetInfo;

  Twitter() {}
  
  void postTweet(int userId, int tweetId) {
    currentTime++;
    timeToTweetInfo.push_back(make_pair(userId, tweetId));
  }
  
  vector<int> getNewsFeed(int userId) {
    int time = currentTime;
    vector<int> feed;
    while(time >= 0) {
      int tweetedPersonId = timeToTweetInfo[time].first;
      int tweetId = timeToTweetInfo[time].second;
      if(userId == tweetedPersonId || followMap[userId].find(tweetedPersonId) != followMap[userId].end()) {
        feed.push_back(tweetId);
        if(feed.size() == 10) return feed;
      }
      time--;
    }
    return feed;
  }
  
  void follow(int followerId, int followeeId) {
    followMap[followerId].insert(followeeId);
  }
  
  void unfollow(int followerId, int followeeId) {
    if(followMap[followerId].find(followeeId) != followMap[followerId].end()) {
      followMap[followerId].erase(followeeId);
    }
  }
};