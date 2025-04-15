class Twitter {
private:
    struct TweetNode {
        int id;
        int timestamp;
        TweetNode* nextTweet;

        TweetNode(): id(0), timestamp(0), nextTweet(nullptr) {};
        TweetNode(int _id, int _timestamp): id(_id), timestamp(_timestamp), nextTweet(nullptr) {};
        TweetNode(int _id, int _timestamp, TweetNode* _nextTweet) : id(_id), timestamp(_timestamp), nextTweet(_nextTweet) {};
    };

    struct User {
        int id;
        TweetNode* tweetList;

        User(): id(0), tweetList(nullptr) {};
        User(int _id): id(_id), tweetList(nullptr) {};
        User(int _id, TweetNode* _tweetList) : id(_id), tweetList(_tweetList) {};
    };

    unordered_map<int, User*> userMap;
    unordered_map<int, unordered_set<int>> followees; 
    int timestamp = 0;
    const int NUM_POSTS = 10;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        User* user = nullptr;
        if (userMap.find(userId) == userMap.end()) {
            user = new User(userId);
            userMap[userId] = user;
        } else {
            user = userMap[userId];
        }

        TweetNode* tweet = new TweetNode(tweetId, timestamp++);

        tweet->nextTweet = user->tweetList;
        user->tweetList = tweet;

        // cout << userId << "-" << user->tweetList->id << endl;
    }
    
    vector<int> getNewsFeed(int userId) {
        if (userMap.find(userId) == userMap.end()) {
            return {};
        }
        
        vector<int> tweets;
        // Max heap
        priority_queue<TweetNode*, vector<TweetNode*>, decltype([](const auto &tweet1, const auto &tweet2){
            return tweet1->timestamp < tweet2->timestamp;
        })> pq;

        User *user = userMap[userId];
        if (user->tweetList) {
            pq.push(user->tweetList);
        }

        for (int followeeId : followees[userId]) {
            User *followee = userMap[followeeId];
            if (followee->tweetList) {
                pq.push(followee->tweetList);
            }
        }

        while (tweets.size() < NUM_POSTS && !pq.empty()) {
            TweetNode* tweet = pq.top(); pq.pop();
            tweets.push_back(tweet->id);

            if (tweet->nextTweet) {
                pq.push(tweet->nextTweet);
            }
        }

        return tweets; 
    }
    
    void follow(int followerId, int followeeId) {
        if (userMap.find(followerId) == userMap.end()) {
            userMap[followerId] = new User(followerId);
        }

        if (userMap.find(followeeId) == userMap.end()) {
            userMap[followeeId] = new User(followeeId);
        }

        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (userMap.find(followerId) == userMap.end()) {
            userMap[followerId] = new User(followerId);
        }

        if (userMap.find(followeeId) == userMap.end()) {
            userMap[followeeId] = new User(followeeId);
        }

        followees[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */