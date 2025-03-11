class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Handle the base case when the vector is empty.
        if (n == 0) {
            return 0;
        }

        unordered_set<int> s;   // Create an unordered set to store unique elements.
        int cnt = 1;            // Initialize a counter for the current consecutive sequence length.
        int longest = 1;        // Initialize a variable to store the maximum consecutive sequence length.

        // Step 2: Insert all elements of 'nums' into the unordered set 's'.
        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }
        
        int x = 0;  // Initialize a variable to keep track of the current element being processed.

        // Step 3: Iterate through the elements of the unordered set.
        for (auto a : s) {
            // Step 4: If the current element 'a' is the start of a sequence (no 'a-1' in 's'),
            if (s.find(a - 1) == s.end()) {
                cnt = 1;  // Reset the counter.
                x = a;    // Update 'x' to the current element 'a'.

                // Step 5: While consecutive elements exist in 's', increment 'cnt' and 'x'.
                while (s.find(x + 1) != s.end()) {
                    cnt++;
                    x = x + 1;
                }
            }
            
            // Step 6: Update 'longest' with the maximum of 'longest' and 'cnt'.
            longest = max(longest, cnt);
        }

        // Step 7: Return 'longest' as the result, representing the length of the longest consecutive sequence.
        return longest;
    }
};