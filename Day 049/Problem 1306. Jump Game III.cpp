class Solution {
public:
    void solve(int index, const vector<int> &arr, vector<bool> &visited) {
        if (index >= arr.size() || index < 0 || visited[index]) {
            return;
        }

        visited[index] = true;
        int left = index - arr[index];
        solve(left, arr, visited);
        
        int right = index + arr[index];
        solve(right, arr, visited);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        solve(start, arr, visited);

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0 && visited[i] == true) {
                return true;
            }
        }    

        return false;
    }
};