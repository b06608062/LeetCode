#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Twitter {
  unordered_map<int, unordered_set<int>> friends;
  unordered_map<int, vector<pair<int, int>>> tweets;
  int timestamp;

public:
  Twitter() { timestamp = 0; }

  void postTweet(int userId, int tweetId) {
    follow(userId, userId);
    tweets[userId].push_back({timestamp, tweetId});
    timestamp++;
  }

  vector<int> getNewsFeed(int userId) {
    set<pair<int, int>> news;
    for (auto i : friends[userId]) {
      for (int j = tweets[i].size() - 1; j >= 0; j--) {
        if (news.size() < 10)
          news.insert(tweets[i][j]);
        else if (tweets[i][j].first > news.begin()->first) {
          news.erase(news.begin());
          news.insert(tweets[i][j]);
        } else
          break;
      }
    }

    vector<int> results;
    for (auto a : news) {
      results.push_back(a.second);
    }
    reverse(results.begin(), results.end());
    return results;
  }

  void follow(int followerId, int followeeId) {
    friends[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    friends[followerId].erase(followeeId);
  }
};