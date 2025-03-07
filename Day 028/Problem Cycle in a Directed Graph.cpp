class Solution {
  public:
    
    bool dfs(int node, vector<int> &color, vector<vector<int>> &adj) {
        color[node] = 1;
        
        for (int neighbor : adj[node]) {
            if (color[neighbor] == 0) {
                if (dfs(neighbor, color, adj)) {
                    return true;
                }
            } else if (color[neighbor] == 1) {
                return true;
            }
        }
        
        color[node] = 2;
        return false;
    }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int> color (n, 0);
        
        for (int node = 0; node < n; node++) {
            if (!color[node]) {
                if (dfs(node, color, adj)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};