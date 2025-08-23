#include<bits/stdc++.h>

using namespace std;

class FoodRatings {
private:
    struct Cmp {
        bool operator()(const pair<int, string> a, const pair<int, string> b) {
            if (a.first == b.first) {
                return a.second > b.second; //lexical order
            }
            return a.first < b.first; // higher rating food has higher priority
        }
    };

    unordered_map<string, int> foodRatingMap; // {food -> rating}
    unordered_map<string, string> foodCuisineMap; // {food -> cuisine}
    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, Cmp>> cuisineMap;
public:

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodRatingMap[foods[i]] = ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            cuisineMap[cuisines[i]].push({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        foodRatingMap[food] = newRating;
        string cuisine = foodCuisineMap[food];
        cuisineMap[cuisine].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        // Check if the top element is still validated (rating == newestRating)
        while (!cuisineMap[cuisine].empty()) {
            auto [rating, food] = cuisineMap[cuisine].top();
            if (rating == foodRatingMap[food]) break;
            cuisineMap[cuisine].pop();
        }

        return cuisineMap[cuisine].top().second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */