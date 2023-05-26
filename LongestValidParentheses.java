
import java.util.Scanner;

/**
 * Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses
 * substring
 *
 * Example 1:
 *
 * Input: s = "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()".
 *
 * Example 2:
 *
 * Input: s = ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()".
 *
 * Example 3:
 *
 * Input: s = ""
 * Output: 0
 *
 * Constraints:
 *
 *     0 <= s.length <= 3 * 104
 *     s[i] is '(', or ')'.
 */

// DP approach. update DP array for every valid closing parentheses.

public class LongestValidParentheses {

    static int longestValidParentheses(String s) {
        int[] dp = new int[s.length()];
        int leftCount = 0;
        int result = 0;
        for (int i= 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                leftCount++;

            } else if (leftCount > 0) {
                dp[i] = dp[i - 1] + 2;
                dp[i] += (i - dp[i]) >= 0 ? dp[i - dp[i]] : 0;  // combine length with previous longest length
                result = Math.max(result, dp[i]);
                leftCount--;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        sc.close();
        System.out.println(longestValidParentheses(s));
    }

}
