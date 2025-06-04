#include<bits/stdc++.h>

using namespace std;

class FoodRatings {
public:
    unordered_map<string, int> foodRatingsMap;
    unordered_map<string, string> foodCuisinesMap;
    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, decltype([](auto &a, auto &b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    })>> cuisineRatingsMap;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodRatingsMap[foods[i]] = ratings[i];
            foodCuisinesMap[foods[i]] = cuisines[i];
            cuisineRatingsMap[cuisines[i]].push({ratings[i], foods[i]});
        }    
    }
    
    void changeRating(string food, int newRating) {
        foodRatingsMap[food] = newRating;
        string cuisine = foodCuisinesMap[food];
        cuisineRatingsMap[cuisine].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto& pq = cuisineRatingsMap[cuisine];
        while (!pq.empty()) {
            auto [rating, food] = pq.top();
            if (foodRatingsMap[food] == rating) {
                return food;
            }
            pq.pop(); // stale entry, skip
        }
        return ""; // should never reach here
    }
};
