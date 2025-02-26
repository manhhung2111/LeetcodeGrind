class Solution {
public:

    int helper(vector<int> arr, bool greaterFirst) {
        int left = 0, right = 0;

        int answer = 1;

        bool isGreater = greaterFirst;
        while (right < arr.size() - 1) {
            if (isGreater) {
                if (arr[right] > arr[right+1]) {
                    right++;
                    isGreater = !isGreater;
                } else {
                    answer = max(answer, right - left + 1);
                    if (left == right) right++;
                    left = right;

                    isGreater = greaterFirst;
                }
            } else {
                if (arr[right] < arr[right+1]) {
                    right++;
                    isGreater = !isGreater;
                } else {
                    answer = max(answer, right - left + 1);
                    if (left == right) right++;
                    left = right;

                    isGreater = greaterFirst;
                }
            }
        }

        answer = max(answer, right - left + 1);

        return answer;
    }


    int maxTurbulenceSize(vector<int>& arr) {
        int temp1 = helper(arr, true);
        int temp2 = helper(arr, false);

        return max(temp1, temp2);
    }
};