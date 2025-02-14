class Solution {
    public:
        vector<int> countBits(int n) {
           vector<int> answer;
           
           for (int i = 0; i <= n; i++) {
            int count = 0, number = i;
    
            while (number) {
                count += (number & 1);
                number = number >> 1;
            }
    
            answer.push_back(count);
           }
    
            return answer;
        }
    };