import java.util.HashMap;
import java.util.Map;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {
        Map<Integer, TreeNode> treeMap = new HashMap<>();
        Map<TreeNode, TreeNode> parentMap = new HashMap<>();
        
        for (int i = 0; i < descriptions.length; i++) {
            int parent = descriptions[i][0], child = descriptions[i][1], isLeft = descriptions[i][2];
            
            treeMap.putIfAbsent(parent, new TreeNode(parent));
            treeMap.putIfAbsent(child, new TreeNode(child));

            TreeNode parentNode = treeMap.get(parent), childNode = treeMap.get(child);
            parentMap.put(childNode, parentNode);
            if (isLeft == 1) {
                parentNode.left = childNode;
            } else {
                parentNode.right = childNode;
            }
        }

        for (Map.Entry<TreeNode, TreeNode> entry : parentMap.entrySet()) {
            if (!parentMap.containsKey(entry.getValue())) {
                return entry.getValue();
            }
        }

        return null;
    }
}