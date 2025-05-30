import java.util.*;

class Solution {

	void buildGraph(int[][] edges, HashMap<Integer, List<Integer>> graph) {
		int n = edges.length + 1;
		for (int i = 0; i < n; i++) {
			graph.put(i, new ArrayList<>());
		}

		for (int[] edge : edges) {
			graph.get(edge[0]).add(edge[1]);
			graph.get(edge[1]).add(edge[0]);
		}
	}

	ArrayList<int[]> getGraphColors(HashMap<Integer, List<Integer>> graph) {
		int n = graph.size();
		int[] colors = new int[n];
		Arrays.fill(colors, -1);
		colors[0] = 0;

		int[] count = new int[2];

		Queue<Integer> queue = new LinkedList<>();
		queue.add(0);

		while (!queue.isEmpty()) {
			int node = queue.poll();
			int currColor = colors[node];
			count[currColor]++;

			int expectedColor = 1 - currColor;
			for (int neighbour : graph.get(node)) {
				if (colors[neighbour] == -1) {
					colors[neighbour] = expectedColor;
					queue.add(neighbour);
				}
			}
		}

		return new ArrayList<>(Arrays.asList(colors, count));
	}

	public int[] maxTargetNodes(int[][] edges1, int[][] edges2) {
		int n = edges1.length + 1, m = edges2.length + 1;
		HashMap<Integer, List<Integer>> graph1 = new HashMap<>();
		HashMap<Integer, List<Integer>> graph2 = new HashMap<>();

		buildGraph(edges1, graph1);
		buildGraph(edges2, graph2);

		ArrayList<int[]> colors1 = getGraphColors(graph1);
		ArrayList<int[]> colors2 = getGraphColors(graph2);

		int[] result = new int[n];
		for (int i = 0; i < n; i++) {
			if (colors1.getFirst()[i] == 0) {
				result[i] = colors1.getLast()[0] + Math.max(colors2.getLast()[0], colors2.getLast()[1]);
			} else {
				result[i] = colors1.getLast()[1] + Math.max(colors2.getLast()[0], colors2.getLast()[1]);
			}
		}

		return result;
	}
}