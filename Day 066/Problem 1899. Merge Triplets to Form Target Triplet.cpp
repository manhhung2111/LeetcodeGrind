class Solution {
public:

    bool validTriplet(const vector<int> &triplet1, const vector<int> &triplet2) {
        return triplet1[0] <= triplet2[0] && triplet1[1] <= triplet2[1] && triplet1[2] <= triplet2[2];
    }

    bool equalTriplet(const vector<int> &triplet1, const vector<int> &triplet2) {
        return triplet1[0] == triplet2[0] && triplet1[1] == triplet2[1] && triplet1[2] == triplet2[2];
    }

    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> currentTriplet = {0, 0, 0};
        for (vector<int> triplet : triplets) {
            if (validTriplet(triplet, target)) {
                currentTriplet[0] = max(currentTriplet[0], triplet[0]);
                currentTriplet[1] = max(currentTriplet[1], triplet[1]);
                currentTriplet[2] = max(currentTriplet[2], triplet[2]);

                if (equalTriplet(currentTriplet, target)) {
                    return true;
                }
            }
        }

        return false;
    }
};