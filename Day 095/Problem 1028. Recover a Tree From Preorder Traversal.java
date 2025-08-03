import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

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

    class Node {
        int val;
        int depth;
        Node(int val, int depth) {this.val = val; this.depth = depth;}
    }

    private List<Node> buildPath(String traversal) {
        List<Node> path = new ArrayList<>();
        int index = 0;
        while (index < traversal.length()) {
            int depth = 0;
            while (index < traversal.length() && traversal.charAt(index) == '-') {
                depth++;
                index++;
            }

            int val = 0;
            while (index < traversal.length() && Character.isDigit(traversal.charAt(index))) {
                val = val * 10 + (traversal.charAt(index) - '0');
                index++;
            }

            path.add(new Node(val, depth));
        }

        return path;
    }


    public TreeNode recoverFromPreorder(String traversal) {
        List<Node> path = this.buildPath(traversal);
        Stack<TreeNode> stack = new Stack<>();
        TreeNode root = new TreeNode(path.get(0).val);

        stack.push(root);
        for (int i = 1; i < path.size(); i++) {
            TreeNode node = new TreeNode(path.get(i).val);
            while (stack.size() > path.get(i).depth) {
                stack.pop();
            }

            TreeNode parent = stack.peek();
            if (parent.left == null) {
                parent.left = node;
            } else {
                parent.right = node;
            }
        }

        return root;
    }
}