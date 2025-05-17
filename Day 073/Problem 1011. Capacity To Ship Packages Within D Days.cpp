class Solution {
public:
    int totalDays(vector<int>& weights, int capacity) {
        int days = 1;
        int currentWeight = 0;

        for (int i = 0; i < weights.size(); i++) {
            if (currentWeight + weights[i] > capacity) {
                days++;
                currentWeight = 0;
            }
            currentWeight += weights[i];
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int totalWeights = 0;
        int maxWeight = weights[0];
        for (int weight : weights) {
            totalWeights += weight;
            maxWeight = max(weight, maxWeight);
        }

        int low = maxWeight, high = totalWeights;
        int result = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int daysTaken = totalDays(weights, mid);

            if (daysTaken <= days) {
                result = min(result, mid);
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }

        return result;
    }
};