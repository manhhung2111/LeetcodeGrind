class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int countTrue = 0, countFalse = 0;
        int answer = 0;

        int left = 0, right = 0;
        int n = answerKey.size();

        while (right < n) {
            if (answerKey[right] == 'T') countTrue++;
            else countFalse++;

            while (max(countTrue, countFalse) + k < right - left + 1) {
                answer = max(answer, max(countTrue, countFalse) + k);

                if (answerKey[left] == 'T') countTrue--;
                else countFalse--;

                left++;
            }

            right++;
        }

        int length = max(countTrue, countFalse) + k;
        answer = max(answer, min(length, n));

        return answer;
    }
};