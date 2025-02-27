class Solution {
public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        queue<int> q; // storing indexes of negative numbers
        
        int windowStart = 0, windowEnd = 0;
        vector<int> answer;
        while (windowEnd < arr.size()) {
            if (arr[windowEnd] < 0) q.push(windowEnd);
            
            if (windowEnd - windowStart + 1 == k) {
                while (!q.empty() && q.front() < windowStart) {
                    q.pop();
                }
                
                if (q.empty()) answer.push_back(0);
                else answer.push_back(arr[q.front()]);
                
                windowStart++;
            }
            
            windowEnd++;
        }
        
        return answer;
    }
};