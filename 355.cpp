// 355. Design Twitter
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Twitter {
public:
  unordered_map<int, unordered_set<int>> m;
  vector<pair<int, int>> tweets;

  Twitter() {}

  void postTweet(int userId, int tweetId) {
    tweets.push_back({userId, tweetId});
  }

  vector<int> getNewsFeed(int userId) {
    int postCounts = tweets.size();
    vector<int> result;
    int count = 0;
    unordered_set<int> s = m[userId];
    for (int i = postCounts - 1; i >= 0; --i) {
      if (count == 10)
        break;

      auto [hostId, tweetId] = tweets[i];
      if (s.find(hostId) != s.end() || hostId == userId) {
        result.push_back(tweetId);
        count++;
      }
    }

    return result;
  }

  void follow(int followerId, int followeeId) {
    m[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    m[followerId].erase(followeeId);
  }
};
