import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        /**
         * A valid binary tree satisfies the following conditions: 
         * +) Each node has exactly 1 parent (except for the root node)
         * +) Only 1 node that has no parent
         */

        Map<Integer, Integer> parentMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            parentMap.put(i, -1);
        }

        for (int node = 0; node < n; node++) {
            if (leftChild[node] != -1) {
                if (parentMap.get(leftChild[node]) == -1) return false;
                parentMap.put(leftChild[node], node);
            }

            if (rightChild[node] != -1) {
                if (parentMap.get(rightChild[node]) == -1) return false;
                parentMap.put(rightChild[node], node);
            }
        }

        int rootNodes = 0;
        for (Map.Entry<Integer, Integer> entry : parentMap.entrySet()) {
            int child = entry.getKey(), parent = entry.getValue();
            System.out.println(child + "-" + parent);
            if (parent == -1) rootNodes++;
        }

        return rootNodes == 1;
    }
}