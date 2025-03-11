class DSU {
public:
    vector<int> parent, rank;

    void makeSet(int n) {
        parent.resize(n, 0);
        rank.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        DSU dsu;
        dsu.makeSet(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j]) {
                    int node1 = dsu.find(i);
                    int node2 = dsu.find(j);

                    if (node1 != node2) {
                        dsu.unite(node1, node2);
                    }
                }
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            if (i == dsu.parent[i]) {
                result++;
            }
        }

        return result;
    }
};