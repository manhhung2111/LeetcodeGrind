class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> time;
        for (int i = 0; i < dist.size(); i++) {
            int totalTime = (int)dist[i] / speed[i] + (dist[i] % speed[i] == 0 ? 0 : 1);
            time.push_back(totalTime);
        }

        if (time.size() > 1) sort(time.begin(), time.end());

        int index = 1, minutes = 2;
        while (true) {
            if (index < time.size() && time[index] >= minutes) {
                index++;
                minutes++;
            } else {
                break;
            }
        }

        return index;
    }
};