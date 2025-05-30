import java.util.Stack;

class Solution {
	public int minSwaps(String s) {
		Stack<Character> stk = new Stack<>();
		int mismatch = 0;
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			if (c == '[') {
				stk.push(c);
			} else {
				if (!stk.isEmpty() && stk.peek() == '[') {
					stk.pop();
				} else {
					mismatch++;
				}
			}
		}

		return (mismatch + 1) / 2;
	}
}