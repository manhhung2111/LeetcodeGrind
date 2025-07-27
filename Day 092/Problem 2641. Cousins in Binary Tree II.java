import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Queue;

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
    public TreeNode replaceValueInTree(TreeNode root) {
        if (root == null) return null;

        Queue<TreeNode> queue = new ArrayDeque<>();
        HashMap<TreeNode, TreeNode> parentMap = new HashMap<>();
        HashMap<TreeNode, Integer> sumMap = new HashMap<>();

        root.val = 0;
        queue.add(root);
        
        while (!queue.isEmpty()) {
            int n = queue.size();
            List<TreeNode> list = new ArrayList<>();
            int levelSum = 0;

            for (int i = 0; i < n; i++) {
                TreeNode node = queue.poll();
                list.add(node);
                levelSum += node.val;
                int sum = 0;
                
                if (node.left != null) {
                    parentMap.put(node.left, node);
                    queue.add(node.left);
                    sum += node.left.val;
                }
                
                if (node.right != null) {
                    parentMap.put(node.right, node);
                    queue.add(node.right);
                    sum += node.right.val;
                }

                sumMap.put(node, sum);
            }

            for (int i = 0; i < list.size(); i++) {
                TreeNode node = list.get(i);
                if (!parentMap.containsKey(node)) {
                    node.val = 0;
                } else {
                    node.val = levelSum - sumMap.get(parentMap.get(node));
                }
            }
        }
        
        return root;
    }

    private void invertTree(TreeNode root) {
        if (root == null) return;

        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;

        invertTree(root.left);
        invertTree(root.right);
    }

    private boolean isSameTree(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) return true;
        if (root1 == null || root2 == null) return false;

        return root1.val == root2.val && isSameTree(root1.left, root2.left) && isSameTree(root1.right, root2.right);
    }

    public boolean isSymmetric(TreeNode root) {
        invertTree(root);
        return isSameTree(root.left, root.right);
    }
}