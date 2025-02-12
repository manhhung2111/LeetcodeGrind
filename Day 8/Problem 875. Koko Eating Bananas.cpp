class Solution {
    public:
        long eatTime(vector<int> piles, long speed) {
            long time = 0;
    
            for (int pile : piles) {
                if (pile % speed != 0) {
                    time += pile / speed + 1;
                } else {
                    time += pile /speed;
                }
            }
    
            return time;
        }
        
        int minEatingSpeed(vector<int>& piles, int h) {
            if (piles.size() > 1) {
                sort(piles.begin(), piles.end());
            }
    
            int answer = -1;
            int low = 1, high = piles.back();
            while (low <= high) {
                long speed = low + (high - low)/2;
    
                long time = eatTime(piles, speed);
                if (time <= h) {
                    answer = speed;
                    high = speed - 1;
                } else {
                    low = speed + 1;
                }
            }
    
            return answer;
        }
    };