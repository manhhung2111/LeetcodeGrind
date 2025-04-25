class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> count;
        sort(hand.begin(), hand.end());
        for (int num : hand) count[num]++;

        for (int num : hand) {
            if (count[num] > 0) {
                for (int i = 0; i < groupSize; i++) {
                    if (count[num + i] <= 0) return false;
                    count[num + i]--;
                }
            }
        }

        return true;
    }
};