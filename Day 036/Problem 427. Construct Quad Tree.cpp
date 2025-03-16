/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    bool helper(int i, int j, const vector<vector<int>> &grid) {
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                if (grid[x][y] != grid[i][j]) return false;
            }
        }

        return true;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (n == 1) {
            bool val = grid[0][0] == 1 ? true : false;
            return new Node(val, true);
        }

        bool isLeaf = true;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (!helper(i, j, grid)) {
                    isLeaf = false;
                    break;
                }
            }
        }

        if (isLeaf) {
            bool val = grid[0][0] == 1 ? true : false;
            return new Node(val, true);
        }

        vector<vector<int>> topLeft, topRight, bottomLeft, bottomRight;
        int mid = n / 2;
        topLeft.resize(mid, vector<int>(mid));
        topRight.resize(mid, vector<int>(mid));
        bottomLeft.resize(mid, vector<int>(mid));
        bottomRight.resize(mid, vector<int>(mid));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i < mid && j < mid) {
                    topLeft[i][j] = grid[i][j];
                } else if (i < mid && j >= mid) {
                    topRight[i][j - mid] = grid[i][j];
                } else if (i >= mid && j < mid) {
                    bottomLeft[i - mid][j] = grid[i][j];
                } else if (i >= mid && j >= mid) {
                    bottomRight[i - mid][j - mid] = grid[i][j];
                }
            }
        }

        Node *root = new Node(true, false);
        root->topLeft = construct(topLeft);
        root->topRight = construct(topRight);
        root->bottomLeft = construct(bottomLeft);
        root->bottomRight = construct(bottomRight);

        return root;
    }
};