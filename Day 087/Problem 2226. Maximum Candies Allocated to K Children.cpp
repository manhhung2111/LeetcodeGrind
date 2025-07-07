class Solution {
public:
    long long numberOfChildren(vector<int>& candies, int candy) {
        long long children = 0;
        for (int i = 0; i < candies.size(); i++) {
            children += (long long)candies[i] / candy;
        }

        return children; 
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1;
        int right = *max_element(candies.begin(), candies.end());

        int result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long children = numberOfChildren(candies, mid);

            if (children >= k) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }   

        return result;  
    }
};