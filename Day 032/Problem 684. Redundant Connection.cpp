class DSU {
public:
    vector<int> rank;
    vector<int> parent;

    void initialize(int n) {
        rank.resize(n, 0);
        parent.resize(n, 0);

        for (int i = 0; i < n; i++) {
            rank[i] = 1;
            parent[i] = i;
        }
    }    

    int find(int node) {
        if (node == parent[node]) return node;
        parent[node] = find(parent[node]);
        return parent[node];
    }

    void unite(int node1, int node2) {
        node1 = find(node1);
        node2 = find(node2);

        if (node1 == node2) return;

        if (rank[node1] > rank[node2]) {
            parent[node2] = node1;
        } else if (rank[node1] < rank[node2]) {
            parent[node1] = node2;
        } else {
            parent[node2] = node1;
            rank[node1]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu;
        dsu.initialize(edges.size() + 1);
        for (vector<int> edge : edges) {
            if (dsu.find(edge[0]) == dsu.find(edge[1])) {
                return edge;
            }

            dsu.unite(edge[0], edge[1]);
        } 
        return {-1, -1};
    }
};