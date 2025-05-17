class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        if (people.size() == 1) return 1;
        sort(people.begin(), people.end());

        int left = 0, right = people.size() - 1;
        int result = 0;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++; 
            }
            result++;
            right--;
        }

        return result;
    }
};